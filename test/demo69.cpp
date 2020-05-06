//
// Created by Administrator on 2020/5/6.
//

#include <iostream>
#include <string>

using namespace std;

//class Base
//{
//public:
//    void func();
//    void func(int a);
//
//public:
//    int m_a;
//};
//void Base::func() {
//    cout<<"base\n";
//}
//void Base::func(int a) {
//    m_a=a;
//    cout<<"base a="<<m_a<<endl;
//}
//class A:public Base
//{
//public:
//    void func();
//    void func(string b);
//
//public:
//    int m_b;
//};
//void A::func() {
//    cout<<"a\n";
//}
//void A::func(string b) {
//    cout<<"a b="<<b<<endl;
//}
class Base{
public:
    //virtual void func();
    void func();

public:
    int m_a;
};
void Base::func() {
    cout<<"base func\n";
}
class A:public Base
{
public:
    //virtual void func();
    void func();
public:
    int m_b;
};
void A::func() {
    cout<<"a func\n";
}
int main()
{
//    Base a;
//    A b;
//    a.func();
//    b.func();
//
//    a.func(100);
//    b.func((char*)"china");

//使用了基类去调用成员函数，成员函数并没有虚函数的话，也就没有虚函数表成员了
//base:func(this=&base) A:func(this=&base)
//如果有虚函数就会新添加一个虚函数表
//base:func(this=&base) A:func(this=&A)
    Base *a;
    a = new Base();
    a->func();

    a = new A();
    a->func();
    return 0;
}