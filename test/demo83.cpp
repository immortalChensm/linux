//
// Created by Administrator on 2020/5/11.
//

#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

template <typename T,typename Y>
class Person
{
public:
    Person(T a,Y b);

public:
    T & show();
    friend class A;
    friend class B;

private:
    T m_a;
    Y m_b;
};

template <typename T,typename Y>Person<T,Y>::Person(T a, Y b):m_a(a),m_b(b) {}
template <typename T,typename Y>T & Person<T,Y>::show() {


    //cout<<this->m_a<<this->m_b<<endl;
    //cout<<(typeid(this->m_a).name())<<endl;
    if (typeid(this->m_a) == typeid(int)){
        //cout<<this->m_a<<this->m_b<<endl;
        cout<<"int\n";
    }else{
        //cout<<this->m_a.m_name<<endl;
        cout<<"obj\n";
    }
    return m_a;
}

class A
{
public:
    A(string name);

public:
    string m_name;
};
A::A(string name):m_name(name) {}
class B
{
public:
    B(string name);

public:
    string m_name;
};
B::B(string name):m_name(name) {}
int main()
{
    int a=100;
    int b=200;
    Person<int,int> c(a,b);
    int &d = c.show();
    cout<<d<<endl;

    d=300;
    c.show();

    A a1((char*)"a");
    B b2((char*)"b");

    Person<A,B> f(a1,b2);
    A t=f.show();
    cout<<t.m_name<<endl;


    return 0;
}