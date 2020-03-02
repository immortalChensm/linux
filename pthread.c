//
// Created by 1655664358@qq.com on 2020/2/28.
//
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <windows.h>
pthread_t tid;
const char *message="hello";
int global=6;

void *speaking(void *args)
{
    pid_t pid;
    pthread_t tid;
    pid = getpid();
    tid = pthread_self();
    global++;
    printf("%d-%u is speaking %s-%d\n",pid,tid,message,global);
    return ((void*)0);
}
void *talking(void *args)
{
    pid_t pid;
    pthread_t tid;
    pid = getpid();
    tid = pthread_self();
    global++;
    printf("%d-%u is talking %s-%d\n",pid,tid,message,global);
    return ((void*)0);
}
int main()
{

    int status;
    status = pthread_create(&tid,NULL,speaking,NULL);
    status = pthread_create(&tid,NULL,talking,NULL);

    Sleep(2);

    printf("run over\n");

    return 0;
}
