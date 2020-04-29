//
// Created by Administrator on 2020/4/29.
//

#include <iostream>
#include <string>
//向上转型  把派生类对象赋值给基类
using namespace std;

class A{
public:
    int m_a;
public:
    A(int a);

public:
    void display();
};
A::A(int a):m_a(a) {}
void A::display() {
    cout<<"m_a="<<this->m_a<<endl;
}

class B:public A{
public:
    B(int a,int b);

public:
    int m_b;
public:
    void display();
};
B::B(int a, int b):A(a),m_b(b) {}
void B::display() {
    cout<<"m_a="<<m_a<<",m_b="<<this->m_b<<endl;
}

int main()
{
    A a(10);
    B b(100,200);
    a.display();
    b.display();

    cout<<"*****************\n";
    a = b;
    a.display();
    b.display();
    return 0;
}