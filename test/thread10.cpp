//
// Created by Administrator on 2020/7/22.
//

#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <mutex>
#include <list>
#include <condition_variable>
#include <string.h>
using namespace std;

class semaphore
{
private:
    std::mutex _mutex;
    int _wake=0;
    int _wait=0;
    std::condition_variable _cond;
public:
    void wait()
    {
        std::unique_lock<std::mutex> lock(_mutex);
        if(--_wait<=0){

            _cond.wait(lock,[this](){

                return _wake>0;
            });
        }
    }
    void wakeup()
    {
        std::unique_lock<std::mutex> lock(_mutex);
        if(++_wait<=0){

            ++_wake;
            _cond.notify_one();
        }
    }
};
class A{

private:
    bool _isRun=false;
    semaphore _sem;
public:

    void Start(int i)
    {
        _isRun = true;
        std::thread t(&A::run,this,i);
        t.detach();

    }
    ~A()
    {
        //cout<<"~ A  exit begin\n";
        Close();
        //cout<<"~ A  exit end\n";
    }
    void Close()
    {
        if(_isRun){
            cout<<"A exit begin\n";
            _isRun = false;
            _sem.wait();
            cout<<"A exit end\n";
        }
    }

    void run(int i)
    {
        while(_isRun){

            cout<<"A::run()"<<i<<endl;
            std::chrono::milliseconds t(200);
            std::this_thread::sleep_for(t);
        }
        cout<<"A run exit\n";
        _sem.wakeup();
    }
};

class Worker
{
private:
    std::list<A*> tasks;
    bool _isRun=false;
    semaphore _sem;
public:
    ~Worker()
    {
        //cout<<"~ Worker  exit \n";
    }

    void Start()
    {
        for(int i=0;i<2;i++){

            A *obj = new A();
            tasks.push_back(obj);
            obj->Start(i);
        }
        _isRun=true;
        std::thread t(&Worker::Run,this);
        t.detach();

    }
    void Close()
    {

        if(_isRun){
            cout<<"worker exit begin\n";
            _isRun = false;
            _sem.wait();

            for(auto iter:tasks){

                delete iter;
            }
            cout<<"worker exit end\n";
        }
    }

    void Run()
    {
        while(_isRun){
            cout<<"Worker::run()"<<endl;
            std::chrono::milliseconds t(200);
            std::this_thread::sleep_for(t);
        }
        cout<<"worker run exit\n";
        _sem.wakeup();
    }
};

int main()
{

    Worker w;
    w.Start();


    while(true){

        char cmd[128];
        scanf("%s",cmd);
        if(strcmp(cmd,"exit")==0){
            w.Close();
            break;
        }
    }

    printf("server exit.");

    while(1){
        std::chrono::milliseconds t(200);
        std::this_thread::sleep_for(t);
    }
    return 0;

}
