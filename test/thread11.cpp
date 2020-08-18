//
// Created by Administrator on 2020/8/6.
//


#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <mutex>
#include <list>
#include <condition_variable>
#include <string.h>
#include <windows.h>
using namespace std;


class Demo
{
public:
    bool _isRun=false;
    std::mutex _mutex;
    void Close()
    {
        std::lock_guard<std::mutex> lc(_mutex);
        if (_isRun){

            _isRun = false;
        }
    }
    void Run()
    {
        _isRun = true;
        while(_isRun){

            std::chrono::milliseconds t(200);
            std::this_thread::sleep_for(t);

            cout<<"threadId="<<std::this_thread::get_id()<<"run"<<endl;

        }
        FILE *f = fopen("run.txt","w");
        fprintf(f,"%d,%#x\n",_isRun,this);
        fclose(f);
        cout<<"threadId="<<std::this_thread::get_id()<<"run over"<<endl;

    }
};


void test()
{
        cout<<"threadId="<<std::this_thread::get_id()<<"run1"<<endl;
        cout<<"threadId="<<std::this_thread::get_id()<<"run2"<<endl;
        cout<<"threadId="<<std::this_thread::get_id()<<"run3"<<endl;
        cout<<"threadId="<<std::this_thread::get_id()<<"run4"<<endl;
        cout<<"threadId="<<std::this_thread::get_id()<<"run5"<<endl;

}

struct abc
{
    int _a;
    int _c;
};
int main()
{

    abc *data = (abc*)new char[8];

    data->_a=10;
    data->_c=100;

    cout<<data->_a<<data->_c<<endl;

//    Demo obj;
//
//    std::thread t(test);
//
//
//
//
//
//    cout<<"server over1"<<endl;
//    cout<<"server over2"<<endl;
//    cout<<"server over3"<<endl;
//    cout<<"server over4"<<endl;
//    cout<<"server over5"<<endl;
//
//
//
//    t.detach();//线程分离
    return 0;
}