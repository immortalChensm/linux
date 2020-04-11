//
// Created by 1655664358@qq.com on 2020/4/10.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <pthread.h>
#include <time.h>
#include <windows.h>
#include <unistd.h>
pthread_mutex_t mutex;
pthread_cond_t cond;

int rice=0;

void *eat(void *arg)
{

    while (1){
        printf("eat child %#lx thread do start00\n",pthread_self());
        printf("eat child %#lx thread do start01\n",pthread_self());
        pthread_mutex_lock(&mutex);


        printf("eat child %#lx thread do start10\n",pthread_self());
        printf("eat child %#lx thread do start11\n",pthread_self());

        if (rice==0){
            printf("eat child %#lx thread do eat start20\n",pthread_self());
            printf("eat child %#lx thread do eat start21\n",pthread_self());
            pthread_cond_wait(&mutex,&cond);
            printf("eat child %#lx thread do eat start22\n",pthread_self());
            printf("eat child %#lx thread do eat start23\n",pthread_self());
        }else{
            printf("eat child %#lx thread do eat start3\n",pthread_self());
            printf("eat child eat rice %d\n",rice);
            rice=0;
            pthread_cond_signal(&cond);
            printf("eat child %#lx thread do eat start40\n",pthread_self());
            printf("eat child %#lx thread do eat start41\n",pthread_self());
        }

        printf("eat child %#lx thread do start50\n",pthread_self());
        printf("eat child %#lx thread do start51\n",pthread_self());
        pthread_mutex_unlock(&mutex);
        printf("eat child %#lx thread do start6\n",pthread_self());
        //sleep(3);
    }
}

void *cook(void *arg)
{

    while (1){
        printf("cook child %#lx thread do start00\n",pthread_self());
        printf("cook child %#lx thread do start01\n",pthread_self());
        pthread_mutex_lock(&mutex);


        printf("cook child %#lx thread do start10\n",pthread_self());
        printf("cook child %#lx thread do start11\n",pthread_self());

        if (rice==0){
            printf("cook child %#lx thread do cook start20\n",pthread_self());
            rice = 1;
            printf("cook child %#lx thread do cook start21\n",pthread_self());
            pthread_cond_signal(&cond);
            printf("cook child %#lx thread do cook start22\n",pthread_self());
            printf("cook child %#lx thread do cook start23\n",pthread_self());
        }else{
            printf("cook child %#lx thread do cook start30\n",pthread_self());
            printf("cook child %#lx thread do cook start31\n",pthread_self());
            pthread_cond_wait(&mutex,&cond);
            printf("cook child %#lx thread do cook start33\n",pthread_self());
            printf("cook child %#lx thread do cook start34\n",pthread_self());
        }

        printf("cook child %#lx thread do start40\n",pthread_self());
        printf("cook child %#lx thread do start41\n",pthread_self());
        pthread_mutex_unlock(&mutex);
        printf("cook child %#lx thread do start5\n",pthread_self());
        //sleep(2);
    }
}
int main()
{


    pthread_mutex_init(&mutex,NULL);
    pthread_cond_init(&cond,NULL);



    pthread_t tid1,tid2;
    pthread_create(&tid1,NULL,eat,NULL);
    pthread_create(&tid2,NULL,cook,NULL);



    printf("main thread run\n");
    //pthread_mutex_lock(&mutex);
    //pthread_cond_wait(&mutex,&cond);
    //sleep(5);
    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);
    printf("main thread will run finish\n");

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);
    return 0;
}