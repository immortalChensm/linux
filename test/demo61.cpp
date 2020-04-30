//
// Created by Administrator on 2020/4/30.
//

#include <iostream>
#include <string>

using namespace std;

class A{
public:
    A(int a);

public:
    void display();

public:
    int m_a;
};
A::A(int a):m_a(a) {}
void A::display() {
    cout<<"class A:m_a="<<m_a<<endl;
}

class B:public A{
public:
    B(int a,int b);

public:
    void display();

protected:
    int m_b;
};
B::B(int a,int b):A(a),m_b(b){}
void B::display() {
    cout<<"class B:m_a="<<m_a<<",m_b="<<m_b<<endl;
}

class C{
public:
    C(int c);

public:
    void display();

protected:
    int m_c;
};
C::C(int c):m_c(c) {}
void C::display() {
    cout<<"class C:m_c="<<m_c<<endl;
}

class D:public B,public C{
public:
    D(int a,int b,int c,int d);

public:
    void display();

private:
    int m_d;
};
D::D(int a, int b, int c, int d):B(a,b),C(c),m_d(d) {}
void D::display() {
    cout<<"class D:m_a="<<m_a<<",m_b="<<m_b<<",m_c="<<m_c<<",m_d="<<m_d<<endl;
}

int main()
{

    A *a = new A(1);
    B *b = new B(2,20);
    C *c = new C(3);
    D *d = new D(4,40,400,4000);

    cout<<a<<endl;
    printf("%#x\n",&(a->m_a));
    a = d;
    a->display();
    b = d;
    b->display();
    c = d;
    c->display();

    cout<<"******************************\n";
    cout<<"a="<<a<<endl;
    cout<<"b="<<b<<endl;
    cout<<"c="<<c<<endl;
    cout<<"d="<<d<<endl;


    return 0;
}