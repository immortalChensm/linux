//
// Created by Administrator on 2020/5/15.
//

#include <iostream>
#include <string>
#include <pthread.h>
#include <unistd.h>
using namespace std;

int number=0;
pthread_mutex_t mutex;
void *write(void *arg)
{
    while (1){
        pthread_mutex_lock(&mutex);
        number++;
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
}
void *print(void *arg)
{
    while (1){
        pthread_mutex_lock(&mutex);
        number++;
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
}
void *show(void *arg)
{
    while (1){
        pthread_mutex_lock(&mutex);
        cout<<number<<endl;
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
}
int main(void)
{

    pthread_t tid1,tid2,tid3;
    pthread_mutex_init(&mutex,NULL);

    pthread_create(&tid1,NULL,write,NULL);
    //pthread_create(&tid3,NULL,print,NULL);
    pthread_create(&tid2,NULL,show,NULL);

    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);
    //pthread_join(tid3,NULL);

    pthread_mutex_destroy(&mutex);

    return 0;
}