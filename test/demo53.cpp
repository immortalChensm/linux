//
// Created by Administrator on 2020/4/28.
//

#include <iostream>
#include <string>
//继承的构造函数和析构函数运行顺序
using namespace std;

class A{
public:
    A(){
        cout<<"A 1\n";
    }
    ~A(){
        cout<<"A 2\n";
    }
};
class B:public A{
public:
    B(){
        cout<<"B 1\n";
    }
    ~B(){
        cout<<"B 2\n";
    }
};
class C:public B{
public:
    C(){
        cout<<"C 1\n";
    }
    ~C(){
        cout<<"C 2\n";
    }
};
int main()
{
    C test;
    return 0;
}