//
// Created by Administrator on 2020/5/18.
//

#include <iostream>
#include <string>

using namespace std;

template<class T1,class T2>
class A{
public:
    T1 v1;
    T2 v2;
};
template<class T>
class B:public A<int,double>{
public:
    T v;
};

int main()
{
    B<char *> b;

    b.v1=100;
    b.v2=24.56;
    b.v=(char*)"hello";

    cout<<b.v1<<b.v2<<b.v<<endl;

    return 0;
}