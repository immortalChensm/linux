//
// Created by Administrator on 2020/5/18.
//

#include <iostream>
#include <string>
//普通类继承模板类
using namespace std;

template <class T>
class A{
public:
    T v1;
    int n;
};
class B:public A<int>
{
public:
    double v;
};
int main()
{
    B obj;
    obj.v=12.4556;
    obj.v1=100;
    obj.n=200;

    cout<<obj.v<<obj.v1<<obj.n<<endl;
    return 0;
}