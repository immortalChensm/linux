//
// Created by Administrator on 2020/4/28.
//

#include <iostream>
#include <string>
//c++继承时的内存对象模型
//对象的成员变量所占用的内存单独存储【堆栈】，而函数放在代码区
//虽然继承了，但是成员的变量所占用的内存【实例化方式决定存储区域要么堆，要么栈】都是累加的
using namespace std;

class A
{
protected:
    int m_a;
    int m_b;
public:
    void display();
    A(int a,int b);
};
A::A(int a, int b):m_a(a),m_b(b) {}
void A::display() {
   cout<<"m_a="<<m_a<<"m_b="<<m_b<<endl;
}

class B:public A{
protected:
    int m_c;
public:
    void display();
    B(int a,int b,int c);
};
B::B(int a, int b, int c):A(a,b),m_c(c) {}
void B::display() {
    cout<<"m_a="<<m_a<<"m_b="<<m_b<<"m_c="<<m_c<<endl;

    printf("a=%#x,b=%#x,c=%3x\n",&m_a,&m_b,&m_c);
}

class C:public B{
private:
    int m_d;
    int m_b;//成员遮蔽变量
    int m_c;//成员遮蔽变量
public:
    C(int a,int b,int c,int d);

public:
    void display();
};
C::C(int a, int b, int c, int d):B(a,b,c),m_b(b),m_c(c),m_d(d) {}
void C::display() {
    //printf("a=%d,b=%d,c=%d,d=%d\n",m_a,m_b,m_c,m_d);
    //printf("a=%#x,b=%#x,c=%#x,d=%x\n",&m_a,&m_b,&m_c,&m_d);
    //printf("A::a=%d,A::b=%d,A::b=%d,B::c=%d,c=%d,d=%d\n",m_a,A::m_b,m_b,B::m_c,m_c,m_d);
    printf("A::a=%d,A::b=%d,C::c=%d",m_a,A::m_b,B::m_c);
    printf("C::b=%d,C::c=%d,C::d=%d\n",m_b,m_c,m_d);

    printf("A::a=%#x,A::b=%#x,C::c=%#x\n",&m_a,&(A::m_b),&(B::m_c));
    printf("C::b=%#x,C::c=%#x,C::d=%#x\n",&m_b,&m_c,&m_d);
}
int main()
{
    A obj_a(10,20);
    B obj_b(100,200,300);

    obj_a.display();
    obj_b.display();

    C obj_c(1,2,3,4);
    obj_c.display();

    return 0;
}
