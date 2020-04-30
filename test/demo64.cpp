//
// Created by Administrator on 2020/4/30.
//

#include <iostream>
#include <string>

using namespace std;

class Base{
public:
    Base();
    virtual ~Base();//声明为虚函数后，对象要调用的成员方法由【实例化的类】派生类决定

protected:
    char *str;
};

Base::Base() {
    str = new char[100];
    cout<<"base constructor\n";
}
Base::~Base() {
    delete [] str;
    cout<<"base destructor\n";
}

class Derived:public Base{
public:
    Derived();
    ~Derived();

private:
    char *name;
};
Derived::Derived() {
    name=new char[100];
    cout<<"derived constructor\n";
}
Derived::~Derived() {
    delete [] name;
    cout<<"derived destructor\n";
}

int main()
{
    //非虚函数 调用成员函数由类型决定
    //pb在调用析构函数时，只是调用了自己的，派生类并没有调用
    Base *pb = new Derived();
    delete pb;

    cout<<"****************\n";

    //这个基类，派生类都调用了
    Derived *pd = new Derived();
    delete pd;

    return 0;
}