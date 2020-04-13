//
// Created by Administrator on 2020/4/11.
//

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <assert.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/epoll.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <libgen.h>
//进程池 高效的半同步/半异步并发编程模式
#define MAX_EVENT_NUMBER 1024
int sockfd=0;
typedef struct process
{
    pid_t pid;
    int pipefd[2];
}process_t;
typedef struct instance
{
    process_t *procs;
    int process_number;
    int process_idx;
}instance_t;

int stop=0;
int epollfd=0;
int sig_pipe[2];
#define BUFFER_SIZE 1024
int setnonblocking(int fd)
{
    int old_option = fcntl(fd,F_GETFL);
    int new_option = old_option|O_NONBLOCK;
    fcntl(fd,F_SETFL,new_option);
    return new_option;
}
int addfd(int epollfd,int fd)
{
    struct epoll_event event;
    event.data.fd = fd;
    event.events = EPOLLIN|EPOLLET;
    epoll_ctl(epollfd,EPOLL_CTL_ADD,fd,&event);
    setnonblocking(fd);
    return 0;
}
void sig_handler(int sig)
{
    int msg = sig;
    printf("收到中断%d\n",sig);
    send(sig_pipe[1],(char*)&msg,1,0);
}
void addsig(int sig,void (*handler)(int))
{
    struct sigaction act;
    memset(&act,0, sizeof(act));
    act.sa_handler = handler;
    act.sa_flags|=SA_RESTART;
    sigfillset(&act.sa_mask);
    sigaction(sig,&act,NULL);

}
int setup_sig_pipe()
{
    epollfd = epoll_create(5);

    int ret = socketpair(PF_UNIX,SOCK_STREAM,0,sig_pipe);
    if (ret<0){
        printf("socketpair error %s\n",strerror(errno));
    }
    setnonblocking(sig_pipe[1]);
    addfd(epollfd,sig_pipe[0]);
    addsig(SIGUSR1,sig_handler);
    addsig(SIGUSR2,sig_handler);
    addsig(SIGINT,sig_handler);
    addsig(SIGTERM,sig_handler);
    addsig(SIGCHLD,sig_handler);
}
void worker(instance_t *inst,int listenfd)
{
    //安装自己的中断信号处理事件
    setup_sig_pipe();
    int pipe = inst->procs[inst->process_idx].pipefd[0];
    //安装自己的管道处理事件
    addfd(epollfd,pipe);
    struct epoll_event events[MAX_EVENT_NUMBER];
    int member=0;
    int i=0,j;
    printf("child process %d run\n",getpid());
    char message[BUFFER_SIZE];
    int read_idx=0;
    int idx=0;
    while(!stop){

//        char msg=0;
//        read(inst->procs[inst->process_idx].pipefd[0],&msg,1);
//        if (msg){
//            printf("child process %d read %d\n",getpid(),msg);
//        }
//        sleep(1);
        member = epoll_wait(epollfd,events,MAX_EVENT_NUMBER,-1);

        if (member<0){
            if (errno!=EAGAIN&&errno==EINTR){
                //break;//防止中断
                continue;
            }
        }
        for(i=0;i<member;i++){
            int sockfd = events[i].data.fd;
            if (sockfd==pipe&&events[i].events&EPOLLIN){
                //自己的管道事件

                struct sockaddr_in client;
                socklen_t client_len = sizeof(client);
                int connfd = accept(listenfd,(struct sockaddr*)&client,&client_len);
                if (connfd>0){
                    addfd(epollfd,connfd);
                    printf("new connfd %d\n",connfd);
                }
            }
            else if (sockfd==sig_pipe[0]&&events[i].events&EPOLLIN){
                //自己的中断信号事件
                int signals[1024];
                int ret = recv(sockfd,signals, sizeof(signals),0);
                if (ret<=0){
                    continue;
                }
                for(j=0;j<ret;j++){
                    switch (signals[j]){
                        case SIGCHLD:

                            break;
                        case SIGINT:
                        case SIGTERM:
                            printf("子进程停止\n");
                            stop=1;
                            break;
                    }
                }
            }
            else if (events[i].events&EPOLLIN){
                //连接sockete上的事件

                //char message[1024];
                int ret = recv(sockfd,message+read_idx,BUFFER_SIZE,0);
                if(ret<0){
                    if(errno==EAGAIN){
                        continue;
                    }
                    break;
                }
                else if(ret==0){
                    close(sockfd);
                }else{
                    read_idx+=ret;
                    for(idx=0;idx<read_idx;idx++){
                        if(idx>1&&message[idx-1]==':'||message[idx]==':'){
                            break;
                        }
                    }
                    if(idx==read_idx){
                        continue;
                    }

                    printf("完整接受的内容：%s\n",message);
                }
                read_idx=0;
                printf("准备发往客户端");
                ret = send(sockfd,"hello",5,0);
                printf("send ret =%d\n",ret);
                memset(message,0,sizeof(message));
            }
        }

    }
    exit(0);
}

void master(instance_t *inst,int listenfd)
{

    printf("master %d run\n",getpid());
    int temp=0;
    char msg=1;

    setup_sig_pipe();
    addfd(epollfd,listenfd);
    struct epoll_event events[MAX_EVENT_NUMBER];
    int member=0;
    int i=0;
    int stat;
    int j=0;
    int n=0;
    int k=0;
    pid_t pid;
    while(!stop){

//        process_t* process = (process_t*)&inst->procs[(temp++)%inst->process_number];
//        if (process->pid){
//            write(process->pipefd[1],&msg,1);
//        }
        member = epoll_wait(epollfd,events,MAX_EVENT_NUMBER,-1);
        if (member<0){
            if (errno!=EAGAIN&&errno==EINTR){
                printf("master epoll_wait error %s\n",strerror(errno));
                //break; 注释为了方便strace 跟踪
                continue;
            }
        }
        for(i=0;i<member;i++){
            int sockfd = events[i].data.fd;
            if(sockfd==listenfd){
                process_t* process = (process_t*)&inst->procs[(temp++)%inst->process_number];
                if (process->pid){
                    write(process->pipefd[1],&msg,1);
                }

            }
            else if (sockfd==sig_pipe[0]&&events[i].events&EPOLLIN){

                int signals[1024];
                int ret = recv(sockfd,signals, sizeof(signals),0);
                if (ret<=0){
                    continue;
                }
                //      int k=0;
                for(;k<ret;k++){
                    switch (signals[k]){
                        case SIGCHLD:

                            if((pid=waitpid(-1,&stat,WNOHANG))>0){
                                for(j=0;j<inst->process_number;j++){

                                    if (pid==inst->procs[j].pid){
                                        printf("child %d join\n",pid);
                                        close(inst->procs[i].pipefd[0]);
                                        inst->procs[i].pid=-1;
                                    }
                                }
                                stop=1;
                                for(j=0;j<inst->process_number;j++){
                                    if (inst->procs[j].pid!=-1){
                                        stop=0;
                                        //                         break;
                                    }
                                }
                            }
                            break;
                        case SIGINT:
                        case SIGTERM:
                            //                  int n;
                            printf("准备杀掉子进程\n");
                            for (n=0; n<inst->process_number ; n++) {

                                kill(inst->procs[n].pid,SIGTERM);
                            }
                            break;
                    }
                }
            }
        }
        //sleep(1);
    }


    return;
}
//void sig_handler(int sig)
//{
//  stop=1;
//}
void process_pool(int sockfd,int process_number)
{
    instance_t *inst = (instance_t*)malloc(sizeof(instance_t));
    inst->process_number = process_number;
    inst->procs = (process_t*)malloc(process_number*sizeof(process_t));

    inst->process_idx=0;
    int i,status;
    signal(SIGUSR1,sig_handler);
    for (i = 0; i <process_number ; ++i) {

        pipe(inst->procs[i].pipefd);
        inst->procs[i].pid = fork();
        if(inst->procs[i].pid<0){
            exit(0);
        }
        else if (inst->procs[i].pid>0){
            close(inst->procs[i].pipefd[0]);
            continue;
        }else{
            close(inst->procs[i].pipefd[1]);
            inst->process_idx = i;
            worker(inst,sockfd);
            return;
        }
    }

    master(inst,sockfd);
//    for(i=0;i<inst->process_number;i++){
//        if (waitpid(inst->procs[i].pid,&status,WNOHANG)==0){
//            printf("child %d finished\n",inst->procs[i].pid);
//        }
//    }

    printf("master %d 关闭管道文件和释放proces内存\n",getpid());
    for(i=0;i<inst->process_number;i++){
        //close(inst->procs[i].pipefd[0]);
        close(inst->procs[i].pipefd[1]);
    }
    free(inst->procs);
    return ;
}

int main(int argc,char *argv[])
{


    printf("main process %d run\n",getpid());
    char const *ip = argv[1];
    int port = atoi(argv[2]);

    struct sockaddr_in address;
    memset(&address,0, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_port = htons(port);
    inet_pton(AF_INET,ip,&address.sin_addr);

    int sockfd = socket(PF_INET,SOCK_STREAM,0);
    if (sockfd<0)exit(0);
    bind(sockfd,(struct sockaddr*)&address, sizeof(address));
    listen(sockfd,5);

    process_pool(sockfd,2);
    return 0;
}

