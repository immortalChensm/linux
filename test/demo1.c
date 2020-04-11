//
// Created by 1655664358@qq.com on 2020/4/2.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <fcntl.h>
#include <sys/types.h>
#include <windows.h>
#include <semaphore.h>
int count=0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
sem_t sem;
pthread_key_t key;
void *talk(void *arg)
{
//    pthread_mutex_lock(&mutex);
//    while (count==0){
//        pthread_cond_wait(&cond,&mutex);
//    }
    int v;
    sem_getvalue(&sem,&v);
    printf("%d\n",v);
    sem_wait(&sem);


    printf("talk count=%d\n",count);
    count++;
    //write(1,"talk\n",6);
    //pthread_mutex_unlock(&mutex);
    sem_post(&sem);
    return ((void*)0);
}
void *speak(void *arg)
{
    sem_wait(&sem);
    //pthread_mutex_lock(&mutex);
    printf("speak count=%d\n",count);
    count++;
    //pthread_cond_signal(&cond);
    //write(1,"speak\n",7);
    //pthread_mutex_unlock(&mutex);
    sem_post(&sem);
    return ((void*)0);
}
int main()
{
    pthread_t tid1,tid2;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);
    sem_init(&sem,0,1);
    pthread_create(&tid1,&attr,talk,NULL);
    pthread_create(&tid2,&attr,speak,NULL);
    //write(1,"hello\n",7);

    pthread_cancel(tid1);
    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);
    printf("main count=%d\n",count);
    Sleep(1);

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);
    pthread_attr_destroy(&attr);
    sem_destroy(&sem);

    printf("main count=%d\n",count);
    return 0;
}