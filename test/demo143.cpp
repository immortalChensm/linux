//
// Created by Administrator on 2020/6/11.
//

#include <iostream>
#include <string>

using namespace std;

class A{
public:
    int _a;
    int _b;
};

class B:public A{
public:
    int _c;
    int _d;
};

class C:public A{
public:
    int _e;
    int _f;
};

void func(A *arg)
{
    B *b = (B*)arg;
    cout<<b->_a<<b->_b<<b->_c<<b->_d<<endl;
}
int main()
{
//    A a;
//    a._a=1;
//    a._b=2;
//
//    B b;
//    b._a=10;
//    b._b=20;
//    b._c=3;
//    b._d=4;
//
//    a = b;
//    cout<<a._a<<a._b<<endl;
//    cout<<"******************"<<endl;
//    func(&b);

    int a=100;
    int *b = &a;

    a=300;
    cout<<*b<<endl;




    return 0;
}