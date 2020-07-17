//
// Created by Administrator on 2020/7/17.
//

#include <iostream>
#include <string.h>
#include <thread>
#include <future>
#include <mutex>
#include <list>
using namespace std;
class Factory
{
public:
    std::list<int> machines;
    std::mutex _mutex;
public:
    void workFlow()
    {
        for(int i=0;i<10;i++){
            //_mutex.lock();
            //std::lock_guard<std::mutex> l(_mutex);
            //std::unique_lock<std::mutex> l(_mutex);
            //_mutex.lock();
            //std::unique_lock<std::mutex> l(_mutex,std::adopt_lock);
            std::unique_lock<std::mutex> l(_mutex,std::try_to_lock);
            //std::unique_lock<std::mutex> l(_mutex,std::defer_lock);
           // l.lock();
            if(l.owns_lock()){
                cout<<"thread id="<<std::this_thread::get_id()<<"||workFlow push:"<<i<<endl;
                machines.push_back(i);
            }
            //l.unlock();
           // _mutex.unlock();
        }
    }

    void assembleMachine()
    {
        for(int i=0;i<10;i++){
            _mutex.lock();
            auto x = machines.front();
            cout<<"thread id="<<std::this_thread::get_id()<<"||assembleMachine:"<<x<<endl;
            machines.pop_front();
            _mutex.unlock();
        }
    }
};
int main()
{

    Factory f;
    std::thread t1(&Factory::workFlow,&f);
    std::thread t2(&Factory::assembleMachine,&f);

    t1.join();
    t2.join();


    return 0;
}