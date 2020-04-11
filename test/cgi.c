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
void worker(instance_t *inst)
{
    while(!stop){

        char msg=0;
        read(inst->procs[inst->process_idx].pipefd[0],&msg,1);
        if (msg){
            printf("child process %d read %d\n",getpid(),msg);
        }
        sleep(1);

    }
    exit(0);
}

void master(instance_t *inst)
{

    printf("master %d run\n",getpid());
    int temp=0;
    char msg=1;
    while(!stop){

        process_t* process = (process_t*)&inst->procs[(temp++)%inst->process_number];
        if (process->pid){
            write(process->pipefd[1],&msg,1);
        }
        sleep(1);
    }
    int i=0;
    for (; i<inst->process_number ; i++) {

        kill(inst->procs[i].pid,SIGKILL);
    }
    return;
}
void sig_handler(int sig)
{
    stop=1;
}
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
            worker(inst);
            return;
        }
    }

    master(inst);
    for(i=0;i<inst->process_number;i++){
        if (waitpid(inst->procs[i].pid,&status,WNOHANG)==0){
            printf("child %d finished\n",inst->procs[i].pid);
        }
    }

    printf("master %d 关闭管道文件和释放proces内存\n",getpid());
    for(i=0;i<inst->process_number;i++){
        close(inst->procs[i].pipefd[0]);
        close(inst->procs[i].pipefd[1]);
    }
    free(inst->procs);
    return ;
}

int main()
{
    process_pool(1,3);
    return 0;
}
