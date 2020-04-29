//
// Created by Administrator on 2020/4/29.
//

#include <iostream>
#include <string>
//c++虚继承的构造函数
using namespace std;

class A{
protected:
    int m_a;
public:
    A(int a);
};
A::A(int a):m_a(a) {}

class B:virtual public A{
protected:
    int m_b;
public:
    B(int a,int b);

public:
    void display();
};

B::B(int a, int b):A(a),m_b(b) {}
void B::display() {
    cout<<"m_a="<<m_a<<",m_b="<<m_b<<endl;
}

class C:virtual public A{
protected:
    int m_c;
public:
    C(int a,int c);

public:
    void display();
};
C::C(int a, int c):A(a),m_c(c) {}
void C::display() {
    cout<<"m_a="<<m_a<<",m_c="<<m_c<<endl;
}

class D:public B,public C{
protected:
    int m_d;
public:
    D(int a,int b,int c,int d);

public:
    void display();
};

D::D(int a, int b, int c, int d):A(a),B(88,b),C(99,c),m_d(d) {}
void D::display() {
    cout<<"m_a="<<m_a<<",m_b="<<m_b<<",m_c="<<m_c<<",m_d="<<m_d<<endl;
}

int main()
{
    B b(10,20);
    b.display();

    C c(30,50);
    c.display();

    D d(100,200,300,400);
    d.display();
    return 0;
}