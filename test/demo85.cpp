//
// Created by Administrator on 2020/5/12.
//

#include <iostream>
#include <string>

using namespace std;
//template <typename 类型参数1 ,typename 类型参数2>
//在调用的时候，编译器会根据函数的实例推断出类型参数的数据类型
//但是有时候需要显示的指明类型参数的数据类型
template <typename T1,typename T2>void show(T1 a,T2 b);

template <typename T1>void talk(T1 a,T1 b){
    cout<<a<<b<<endl;
}
int main()
{
    int a=10;
    int b=20;
    show(a,b);

    float c=100.24;
    //talk(a,c);//在调用的时候根据函数实参数据类型 推断出模板参数的类型参数的具体类型  但是这里无法推断出来
    talk<float>(a,c);//显示的指出模板参数的类型参数的数据类型为float
    return 0;
}

template <typename T1,typename T2>void show(T1 a,T2 b)
{
    cout<<a<<b<<endl;

    return;
}