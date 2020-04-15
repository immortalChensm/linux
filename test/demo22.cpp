//
// Created by Administrator on 2020/4/15.
//

#include <iostream>
#include <string>

using namespace std;

class Demo
{
private:
    int m_a;
public:
    Demo(int a);
    ~Demo();
};

Demo::Demo(int a):m_a(a) {}
Demo::~Demo() {
    cout<<m_a<<endl;
}
//全局函数  程序运行结束时  调用析构函数
void func()
{
    //在栈上创建的局部对象
    Demo obj1(1);
}
//全局 同样的道理 在全局数据区
Demo obj2(2);
int main()
{
    //在栈区
    Demo obj3(3);

    //在堆区  调用delete obj5析构函数才调用
    Demo *obj5 = new Demo(5);

    func();

    printf("demo test\n");

    delete obj5;

    return 0;
}