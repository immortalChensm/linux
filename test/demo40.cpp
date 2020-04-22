//
// Created by Administrator on 2020/4/21.
//

#include <iostream>
#include <string>
//c++的引用和指针变量的实现原理细节如下
using namespace std;

int main()
{
    /**
     * a 0x1=10
     */
    int a=10;
    /**
     * r 0x2=0x1
     * int *r=&a
     */
    int &r=a;

    //r=0x1 == *0x1 调用r=*r
    cout<<a<<r<<endl;
    cout<<&a<<"="<<&r<<endl;
    printf("%#x==%#x\n",&a,&r);
    printf("%#x==%#x\n",&a,&r);


    return 0;
}