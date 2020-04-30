//
// Created by Administrator on 2020/4/30.
//

#include <iostream>
#include <string>
//c++虚函数
//对象要调用的成员函数：1不是虚函数且未覆盖的一般由对象前面的数据类型【类】决定成员  2、如果是虚函数且覆盖【遮蔽】了由对象的值【类】决定成员
using namespace std;

class Base
{
public:
    virtual void func();
    virtual void func(int);
};
void Base::func() {
    cout<<"void Base::func()"<<endl;
}
void Base::func(int) {
    cout<<"void Base::func(int)"<<endl;
}

class Derived:public Base{
public:
    void func();
    void func(char *);
};

void Derived::func() {
    cout<<"void Derived::func()"<<endl;
}
void Derived::func(char *) {
    cout<<"void Derived::func(char*)"<<endl;
}

int main()
{
    //对象调用类的普通函数时，根据类调用其成员
    //对象调用类的虚函数时，存在遮蔽，根据对象的地址【类】决定成员函数
    Base *p = new Derived();
    //func 是虚函数  派生类遮蔽 ，此时调用的是Derived类的成员函数func
    p->func();
    //基类是虚函数，但派生类并没有遮蔽覆盖，所以调用的成员函数是base类
    p->func(20);
    //func(char*)不是虚函数，但是p的数据类型是base ，只有成员func(int) func() 并没有func(char*)成员，所以出错
    //p->func((char*)"char");

    return 0;
}