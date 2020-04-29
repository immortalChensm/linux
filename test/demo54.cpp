//
// Created by Administrator on 2020/4/28.
//

#include <iostream>
#include <string>
//c++多继承和多继承时对象的内存模型
using namespace std;

class A{

protected:
    int m_a;//占用4个字节，派生类实例化，所占用的内存大小，由各个基类和派生类的成员变量数量决定
    int m_b;
public:
    A(int a,int b);
    void show();
    ~A();
};

A::A(int a, int b):m_a(a),m_b(b) {
    cout<<"A\n";
}
A::~A() {
    cout<<"~A\n";
}
void A::show() {
    cout<<"m_a="<<m_a<<",m_b="<<m_b<<endl;
}
class B
{
protected:
    int m_c;
    int m_d;
public:
    B(int c,int d);
    void show();
    ~B();
};

B::B(int c, int d):m_c(c),m_d(d) {
    cout<<"B\n";
}
B::~B() {
    cout<<"~B\n";
}
void B::show() {
    cout<<"m_c="<<m_c<<",m_d="<<m_d<<endl;
}

class C:public A,public B{

private:
    int m_e;
public:
    C(int a,int b,int c,int d,int e);
    ~C();
    void display();
};
C::C(int a, int b, int c, int d, int e):A(a,b),B(c,d),m_e(e) {
    cout<<"C\n";
}
C::~C() {
    cout<<"~C\n";
}
void C::display() {
    A::
    show();
    B::show();
    cout << m_a << m_b << m_c << m_d << m_e << endl;
    printf("m_a=%#x,m_b=%#x,m_c=%#x,m_d=%#x,m_e=%#x\n", &m_a, &m_b, &m_c, &m_d, &m_e);
}
int main()
{
    //C test1(1,2,3,4,5);
    //test1.display();

    C *test2 = new C(6,7,8,9,10);
    test2->display();

    //delete [] test2;
    return 0;
}