//
// Created by Administrator on 2020/5/13.
//

#include <iostream>
#include <pthread.h>
#include <windows.h>
#include <unistd.h>
#include <errno.h>
#include <string>
#include <unistd.h>
using namespace std;
class download{
public:
    void show(){
        cout<<"download"<<endl;
    }
};

class upload{
public:
    void show(){
        cout<<"upload"<<endl;
    }
};

void *talk(void *arg)
{
    int i=10;
    download d;
    while(i--){

        //printf("talk ptrhead run\r\n");
        cout<<"talk pthread run"<<endl;
        d.show();
    }
    printf("talk over\n");
    return ((void*)0);
}

void *speak(void *arg)
{
    int j=10;
    upload u;
    while(j--){

        //printf("speak ptrhead run\r\n");
        cout<<"speak pthread run"<<endl;
        u.show();
    }
    printf("speak over\n");
    return ((void*)0);
}
int main()
{
    pthread_t tid1,tid2;

    pthread_create(&tid1,NULL,talk,NULL);
    pthread_create(&tid2,NULL,speak,NULL);

    sleep(2);

    return 0;
}