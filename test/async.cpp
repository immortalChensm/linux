//
// Created by Administrator on 2020/8/21.
//

#include <iostream>
#include <future>
#include <functional>
#include <thread>
#include <atomic>
#include <time.h>
#include <windows.h>
using namespace std;
int test()
{
    cout<<"test"<<endl;
    return 100;
}

class A{
public:
    int _i=0;
public:
    void show()
    {
        while(1){

            std::chrono::milliseconds t(100);
            //if(_mutex.try_lock_for(t)){
            if(_mutex.try_lock_until(chrono::steady_clock::now()+t)){

                cout<<"show functoin:rob mutex"<<endl;
                cout<<_i<<endl;
                _mutex.unlock();
            }else{
                cout<<"do other thing..."<<endl;
            }
        }
    }
    void add()
    {
        while(1){

            //std::lock_guard<std::timed_mutex> lock(_mutex);
           // std::chrono::milliseconds t(1000000000);
            //std::this_thread::sleep_for(t);
            _mutex.lock();
            _i++;
            cout<<"add function:i++"<<endl;
            _mutex.unlock();
        }
    }



private:
    //std::timed_mutex _mutex;
    std::recursive_timed_mutex _mutex;
    std::recursive_mutex _mutex1;
};
int main()
{

    A obj;
    std::thread t1(&A::show,&obj);
    std::thread t2(&A::add,&obj);

    t1.join();
    t2.join();

//    std::future<int> ret = std::async(test);
//
//    cout<<"hi\n";
//
//    cout<<ret.get()<<endl;

//    std::function<int(int)> a = [](int a)->int{
//
//        cout<<a<<endl;
//        return 1;
//    };
//
//    int ret = a(100);
//    cout<<ret<<endl;

//    auto f = std::bind([](int a,int b)->int{
//
//        cout<<a<<b<<endl;
//        },100,placeholders::_1);
//
//    f(1000);

//    std::packaged_task<int(int)> obj(test);
//
//    obj(199);
//
//    std::future<int> ret = obj.get_future();
//
//    cout<<ret.get()<<endl;

//    auto f = [](std::promise<int> &tmp,int t){
//
//        int x=t+100;
//        tmp.set_value(x);
//    };
//
//    std::promise<int> obj;
//    std::thread t(f,std::ref(obj),100);
//
//    t.join();
//
//    std::future<int> ret = obj.get_future();
//    cout<<ret.get()<<endl;
//
//    //
//    cout<<"*************************"<<endl;
//
//    std::promise<int> x1;
//    x1.set_value(100);
//
//    std::future<int> x2 = x1.get_future();
//    cout<<x2.get()<<endl;

//    cout<<"threadid="<<std::this_thread::get_id()<<endl;
//    auto f = [](std::shared_future<int> ret){
//        cout<<"threadid="<<std::this_thread::get_id()<<endl;
//        auto s = ret.get();
//        auto s1 = ret.get();
//        cout<<s<<s1<<endl;
//    };
//
//    auto f1 = [](int a)->int{
//        std::this_thread::sleep_for(std::chrono::seconds(2));
//        cout<<"threadid="<<std::this_thread::get_id()<<endl;
//        return a+100;
//    };
//
//    std::packaged_task<void(std::shared_future<int>)> obj(f);
//
//    //启动新线程
//    std::future<int> f1_ret = std::async(f1,10);
//    std::shared_future<int> fx(f1_ret.share());
//
//    if (fx.valid()){
//        //启动第2个线程
//        std::thread t1(std::ref(obj),fx);
//
//        t1.join();
//    }else{
//        cout<<"fx not value"<<endl;
//    }
//
//
//    std::atomic<int> i{9};
//    i++;
//    cout<<i<<endl;

//    int *obj = new int{10};
//    cout<<*obj<<endl;
//    delete obj;
//
//    std::shared_ptr<int> objx(new int(100));
//    cout<<*objx<<endl;
//
//    std::unique_ptr<int> objy( objx.get());
//
//    cout<<*objy<<endl;
    return 0;
}