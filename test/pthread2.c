//
// Created by Administrator on 2020/4/11.
//

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <windows.h>
#include <time.h>

void *a(void *arg)
{
    while (1){
        printf("a\n");
    }
}
void *b(void *arg)
{
    while (1){
        printf("b\n");
    }
}
int main()
{

    pthread_t tid1,tid2;
    pthread_create(&tid1,NULL,a,NULL);
    pthread_create(&tid2,NULL,b,NULL);

    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);
    return 0;
}