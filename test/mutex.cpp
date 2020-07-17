//
// Created by Administrator on 2020/7/11.
//

#include <iostream>

#include <mutex>
#include <thread>

#include <list>



//创建多个线程|共享数据
using namespace std;

//vector<char> g_s{ 'a','b','c' };
//
//void func(int num)
//{
//    //cout << "begin:" <<num<< endl;
//
//    //cout << "end:" <<num<< endl;
//    cout << "thread_id=" << std::this_thread::get_id() << endl;
//    for (auto iter = g_s.begin(); iter != g_s.end(); iter++) {
//        cout << *iter << endl;
//    }
//}

//class T {
//public:
//    T(int a) :_i(a) {};
//    int _i;
//};
mutex _mutex;
class A
{
public:
    A()
    {

    }
    ~A()
    {

    }
    void inMsgRecQueue()
    {
        for (int i = 0; i < 100000; i++)
        {
            cout << "inMsgRecQueue-insert: " << i << endl;
            _mutex.lock();
            msgRecQueue.push_back(i);
            _mutex.unlock();
        }
    }

    bool outMsgRecQueueProc(int &cmd)
    {
        if (!msgRecQueue.empty())
        {
            cmd = msgRecQueue.front();
            msgRecQueue.pop_front();

            return true;
        }
        return false;
    }
    void outMsgRecQueue()
    {
        int cmd = 0;
        for (int i = 0; i < 100000; i++)
        {
            if (outMsgRecQueueProc(cmd))
            {
                cout << "outMsgRecQueueProc:"<<cmd << endl;

            }
            else {
                cout << "outMsgRecQueue-empty: " << i << endl;
            }
        }
        cout << "outMsg end" << endl;
    }
private:
    list<int> msgRecQueue;

};

int main()
{


    A msgObj;

    std::thread outMsgObj(&A::outMsgRecQueue, msgObj);
    std::thread inMsgObj(&A::inMsgRecQueue, msgObj);


    inMsgObj.join();
    outMsgObj.join();

    //1、保护共享数据  线程操作时把共享数据锁住，操作完，解锁，方便其它线程操作
    cout << "main end" << endl;
    return 0;
}