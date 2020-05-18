//
// Created by Administrator on 2020/5/18.
//

#include <iostream>
#include <string>

using namespace std;
//模板继承
template <class T1,class T2>
class A{
public:
    T1 v1;
    T2 v2;
};
template <class T1,class T2>
class B:public A<T2,T1>{
public:
    T1 v3;
    T2 v4;
};
template <class T>
class C:public B<T,T>
{
public:
    T v5;
};

int main()
{

    A<int,int> a;
    a.v1=10;
    a.v2=20;

    cout<<a.v1<<a.v2<<endl;

    B<int,float> b;
    b.v1=10;
    b.v2=100.456;
    b.v3=20;
    b.v4=12.65;
    cout<<b.v1<<b.v2<<b.v3<<b.v4<<endl;

    C<char> c;
    c.v1='a';
    c.v2='b';
    c.v3='c';
    c.v4='d';
    c.v5='e';

    cout<<c.v1<<c.v2<<c.v3<<c.v4<<c.v5<<endl;
    return 0;
}