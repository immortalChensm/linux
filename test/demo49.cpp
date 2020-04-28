//
// Created by Administrator on 2020/4/28.
//

#include <iostream>
#include <string>
//c++类继承作用域嵌套
//同一个派生类作用域下重名的函数才构成重载，不同作用域下同名函数只会构成遮蔽
class A
{
public:
    int m;
    void func();
};
class B:public A{
public:
    int x;
};
class C:public B{
public:
    int y;
};

void A::func() {
    std::cout<<"hello,world"<<std::endl;
}
int main()
{
    C obj;
    obj.func();
    std::cout<< sizeof(obj)<<std::endl;
    obj.m=100;
    std::cout<<obj.m<<std::endl;
    return 0;
}