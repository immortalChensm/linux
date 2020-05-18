//
// Created by Administrator on 2020/5/18.
//
#include <iostream>
#include <string>

using namespace std;

class A{
public:
    int v2;
};

template <class T>
class B:public A{
public:
    T v;
};

int main()
{
    B<char> obj;

    obj.v2=100;
    obj.v=='a';

    cout<<obj.v<<obj.v2<<endl;

    return 0;
}