//
// Created by Administrator on 2020/5/13.
//

#include <iostream>
#include <string>
#include <pthread.h>
#include <unistd.h>

using namespace std;


void *clean(void *arg)
{
    printf("do clean %s\n",(char*)arg);
    return ((void*)0);
}
void *talk(void *arg)
{
    pthread_t tid;
    pid_t pid;
    pid = getpid();
    tid = pthread_self();

    printf("thread pid %d tid %d start\n",pid,tid);

    pthread_cleanup_push((void*)clean,(void*)"talk first");
    pthread_cleanup_push((void*)clean,(void*)"talk second");

    pthread_cleanup_pop(0);
    pthread_cleanup_pop(0);

    pthread_exit((void*)0);
}
void *speak(void *arg)
{

    printf("speak thread %d start\n",pthread_self());
    pthread_cleanup_push((void*)clean,(void*)"speak first");
    pthread_cleanup_push((void*)clean,(void*)"speak second");

    printf("speak %s\n","i am the best");

    pthread_exit((void*)1);
}
int main()
{

    pthread_t tid1,tid2;
    pthread_create(&tid1,NULL,talk,(void*)1);
    pthread_create(&tid2,NULL,speak,(void*)2);
    void *status;
    pthread_join(tid1,&status);
    printf("thread %d exit code %d\n",tid1,(int)status);
    pthread_join(tid2,&status);
    printf("thread %d exit code %d\n",tid2,(int)status);
    return 0;
}