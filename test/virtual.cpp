//
// Created by Administrator on 2020/7/1.
//

#include <iostream>
#include <string.h>
#include <vector>
#include <map>

using namespace std;
class A{
public:
    A(){
        cout<<"a"<<endl;
    }
    virtual void info()
    {
        cout<<"a info"<<endl;
    }
    //没有virtual 则派生类无法释放
    virtual ~A(){
        cout<<"~a"<<endl;
    }
};

class B:public A{
public:
    B(){
        cout<<"b"<<endl;
    }
    void info()
    {
        A::info();
        cout<<"b info"<<endl;
    }
    ~B(){
        cout<<"~b"<<endl;
    }
};
int main()
{

//    A a;
//    a.info();
//
//    B b;
//    b.info();
//
//
//    a = b;
//    a.info();

    A *a = new B();
    a->info();

    delete a;

//    B *b = new B();
//    b->info();
//
//    delete b;
    return 0;
}