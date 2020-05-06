//
// Created by Administrator on 2020/5/6.
//

#include <iostream>
#include <typeinfo>
using namespace std;
/**
 * 单独的类时：对象内存模型仅仅存储了对象的成员，而共公函数单独存放在代码区  对象一般分配在栈区或是堆区【使用new时分配在堆区，需要手动释放】
 * 继承的类：对象内存模型一般是各个类的【基类，派生类】的成员变量进行累加而已，就算成员遮蔽了也是要累加
 * 多态时：对象内存模型除了存储对象的成员变量时，还会有一个虚函数指针，指向一个使用数组存储【存储虚函数表的入口地址构成的数组为虚函数表】
 * 有些时候在编译时无法确认对象的数据类型，在运行时才动态的确认，称为RTTI机制
 */
class Base
{
public:
    virtual void func();

protected:
    int m_a;
    int m_b;
};
void Base::func() {
    cout<<"base"<<endl;
}
class Derived:public Base
{
public:
    void func();

private:
    int m_c;
};
void Derived::func() {
    cout<<"derived\n";
}

int main()
{
    //在编译期间并不知道p具体数据类型
    //只有运行时才动态的知道
    //静态语言：在编译期间就知道数据类型了，并且显示的定义了数据类型
    //动态语言：只有在运行时才知道数据类型，并且还是动态变化 的
    Base *p;
    int n;

    cin>>n;

    if (n<=100){
        p = new Base();
    }else{
        p = new Derived();
    }

    cout<< typeid(*p).name()<<endl;

    return 0;
}