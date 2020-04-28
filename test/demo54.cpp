//
// Created by Administrator on 2020/4/28.
//

#include <iostream>
#include <string>
//c++多继承
using namespace std;

class A{

protected:
    int m_a;
    int m_b;
public:
    A(int a,int b);
    ~A();
};

A::A(int a, int b):m_a(a),m_b(b) {
    cout<<"A\n";
}
A::~A() {
    cout<<"~A\n";
}
class B
{
protected:
    int m_c;
    int m_d;
public:
    B(int c,int d);
    ~B();
};

B::B(int c, int d):m_c(c),m_d(d) {
    cout<<"B\n";
}
B::~B() {
    cout<<"~B\n";
}

class C:public A,public B{

private:
    int m_e;
public:
    C(int a,int b,int c,int d,int e);
    ~C();
    void show();
};
C::C(int a, int b, int c, int d, int e):A(a,b),B(c,d),m_e(e) {
    cout<<"C\n";
}
C::~C() {
    cout<<"~C\n";
}
void C::show() {
    cout<<m_a<<m_b<<m_c<<m_d<<m_e<<endl;
}

int main()
{
    C test1(1,2,3,4,5);
    test1.show();

    C *test2 = new C(6,7,8,9,10);
    test2->show();
    //delete [] test2;
    return 0;
}