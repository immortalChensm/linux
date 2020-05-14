//
// Created by Administrator on 2020/5/13.
//

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <stddef.h>
void *thread_func(void *arg)
{

    int *val = (int*)arg;

    printf(" a thread\n");

    if(NULL!=arg){

        while(1){

            printf("arguemnt set:%d\n",*val);
            printf("child pthread\n");
        }

    }
}

int main()
{

    pthread_t tid;
    int arg=10;

    pthread_create(&tid,NULL,thread_func,&arg);
    sleep(1);
    printf("main thread!\n");

    printf("时间到，准备结束\n");
    pthread_cancel(tid);

    return 0;
}
