//
// Created by Administrator on 2020/4/29.
//

#include <iostream>
#include <string>
//菱形继承
//派生类D类继承的成员A->C A->B 都有m_a成员，重复
using namespace std;

class A{
protected:
    int m_a;
};
class B:public A{
protected:
    int m_b;
};
class C:public A{
protected:
    int m_c;
};
class D:public B,public C{
protected:
    int m_d;
public:
    void seta(int a){
        //this->m_a=a; 不知道访问哪个  B,C类都有m_a
        B::m_a=a;
    }
    void setb(int b){
        this->m_b=b;
    }
    void setc(int c){
        this->m_c=c;
    }
    void setd(int d){
        this->m_d=d;
    }
};

int main()
{
    D d;
    return 0;
}