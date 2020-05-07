//
// Created by Administrator on 2020/5/6.
//

#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

class A{
public:
    A();
    A(int a,int b);

public:
    int m_a;
    int m_b;
    int m_flag;
public:
    void display();
    A operator-(A &a);
};

A::A():m_a(0),m_b(0) {}
A::A(int a, int b):m_b(b),m_a(a) {}
void A::display() {
    cout<<"display flag="<<m_flag<<endl;
    cout<<"a="<<m_a<<"b="<<m_b<<endl;
}
A A::operator-(A &a) {
    A c;
    c.m_flag=3;
    cout<<"this="<< typeid(this).name()<<this->m_flag<<endl;
    cout<<"a="<< typeid(a).name()<<a.m_flag<<endl;


    c.m_a=this->m_a-a.m_a;
    c.m_b=this->m_b-a.m_b;
    return c;
}

int main()
{
    A a(10,5);
    a.m_flag=1;
    A b(5,2);
    b.m_flag=2;
    A c;
    c.m_flag=5;
    c = a-b-b;
    c.display();

    return 0;
}

