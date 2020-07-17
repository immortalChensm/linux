//
// Created by Administrator on 2020/7/8.
//

#include <stdlib.h>
#include <iostream>
#include <assert.h>
#include <thread>
using namespace std;

class A{
private:
    A()
    {
        cout<<"a"<<endl;
    }
public:
    static A &getInstance()
    {
        static A obj;
        return obj;
    }
    void add()
    {

        if(_counter==0){
            _counter++;
        }
    }
    int getCounter()
    {
        cout<<"_counter:"<<_counter<<endl;
        return _counter;
    }
    int _counter{0};
};
void func()
{
    for(int i=0;i<10000;i++){
        A::getInstance().add();
        A::getInstance().getCounter();
    }

}
int main()
{
//    assert(1==1);
//
//    static int a=10;
//    static int a = 20;
//
//    cout<<a<<endl;

    for(int i=0;i<8;i++){
        thread t(func);
        t.join();
    }

    cout<<"end"<<endl;
    return 0;
}