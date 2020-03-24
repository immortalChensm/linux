#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/epoll.h>
#include <fcntl.h>
#include <sys/types.h>
int pipefd[2];
void worker();

int setnonblocking(int fd)
{
    int old_option  = fcntl(fd,F_GETFL);
    int new_option = old_option|O_NONBLOCK;
    fcntl(fd,F_SETFL,new_option);
    return old_option;
}

int addfd(int epollfd,int fd)
{
    struct epoll_event event;
    event.data.fd = fd;
    event.events = EPOLLIN;
    epoll_ctl(epollfd,EPOLL_CTL_ADD,fd,&event);
    setnonblocking(fd);
}
void sig_handler(int sig)
{
    printf("定时事件到:%d\n",sig);
    //send(pipefd[1],(char*)&sig,1,0);
    write(pipefd[1],(char*)&sig,1);
    alarm(10);
}
void sig_handler1(int sig)
{
    printf("自定义事件到\n");
    //send(pipefd[1],(char*)&sig,1,0);
    write(pipefd[1],(char*)&sig,1);

    //printf("pgid=%d\n",getpid());
}

void sig_handler2(int sig)
{
    int exitCode;
    pid_t pid = wait(&exitCode);
    printf("pid=%d exit\n",pid);

//    pid = fork();
//    if (pid==0){
//       worker();
//    }
//    setpgid(pid,getpid());
    write(pipefd[1],(char*)&sig,1);
}

void sig_handler3(int sig)
{
    printf("sigpipe occur\n");
}

void sig_handler5(int sig)
{
    //printf("子进程终止\");
}

void worker()
{
    //signal(SIGINT,sig_handler5);
   // close(pipefd[1]);
    while(1){
        //char msg;
        //int sig = recv(pipefd[0],&msg,1,0);
        //int sig = read(pipefd[0],&msg,1);
        //if (sig>0){
            printf("------child process %d ,father pid=%d,pgid=%d,rece msg:%d\n",getpid(),getppid(),getpgrp(),1);
       // }
       printf("-----child doing then sleep 1 second\n");
        sleep(3);
    }
}
int main() {

    signal(SIGALRM,sig_handler);
    signal(SIGUSR1,sig_handler1);
    signal(SIGCHLD,sig_handler2);
    signal(SIGPIPE,sig_handler3);
    int i=0;
    alarm(10);
    printf("pid=%d\n",getpid());


    pipe(pipefd);

    pid_t pid = fork();
    if(pid==0){
        worker();
        exit(0);
    }
    //close(pipefd[0]);
    int epollfd = epoll_create(5);
    struct epoll_event events[1];
    //setnonblocking(pipfd[0]);
    addfd(epollfd,pipefd[0]);
    while(1){

        int ret  = epoll_wait(epollfd,events,1,0);
        char msg;
        if (ret>0){

            int sockfd = events[0].data.fd;
            ret = read(sockfd,&msg,1);
            switch(msg){
                case SIGUSR1:
                    printf("SIGUSR1 happen\n");
                    break;
                case SIGALRM:
                    printf("SIGALRM happen\n");
                    break;
                case SIGCHLD:

                        printf("子进程挂了，马上启动新的子进程来服务\n");
                        pid = fork();
                        if (pid==0){
                           worker();
                        }
                        setpgid(pid,getpid());
                    break;
            }
        }
        printf("----father process pid=%d,father pid=%d,gpid=%d,i=%d\n",getpid(),getppid(),getpgid(0),i++);
//        if (i%10==1){
//            alarm(10);
//        }


        sleep(2);
    }
    printf("Hello, World!\n");
    return 0;
}