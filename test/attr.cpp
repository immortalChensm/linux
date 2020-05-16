//
// Created by Administrator on 2020/5/15.
//

#include <iostream>
#include <string>
#include <pthread.h>
#include <unistd.h>
#include <errno.h>

using namespace std;

void *talk(void *arg)
{
    while (1){

        //printf("thread %d running\n",pthread_self());
        cout<<"thread"<<pthread_self()<<"run"<<endl;
        //sleep(1);
    }
    printf("over\n");
}

int main()
{
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_t tid;
    int detachstate;
    pthread_attr_getdetachstate(&attr,&detachstate);
    if (detachstate==PTHREAD_CREATE_DETACHED){
        cout<<"detach thread"<<endl;
    }
    else if (detachstate==PTHREAD_CREATE_JOINABLE){
        cout<<"join thread"<<endl;
    }

    pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);

    pthread_create(&tid,&attr,talk,(void*)"test");
    //pthread_create(&tid,NULL,talk,(void*)"test");

    //pthread_join(tid,NULL);

    printf("main thread %d finish\n",pthread_self());
    return 0;
}