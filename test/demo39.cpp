//
// Created by Administrator on 2020/4/21.
//

#include <iostream>
#include <stdlib.h>
#include <string>
//引用  类似指针【内存地址】
using namespace std;

void swap1(int a,int b);
void swap2(int *p1,int *p2);
void swap3(int &r1,int &r2);

int main()
{

//    int a=10;
//    int &b = a;
//    int *c = &a;
//
//    cout<<"a="<<a<<"b="<<b<<"c="<<*c<<endl;
//
//    cout<<"@a="<<&a<<"@b="<<&b<<endl;
//    cout<<"@c="<<c<<"@a"<<&a<<endl;
//
//    b=100;
//    cout<<a<<b<<*c<<endl;
//
//    *c=300;
//    cout<<a<<b<<*c<<endl;

    //num1 0x1=10
    //num2 0x2=20
    int num1,num2;
    cout<<"input two number:";
    cin>>num1>>num2;
    cout<<num1<<num2<<endl;

    //swap1(num1,num2);
    //swap2(&num1,&num2);
    swap3(num1,num2);
    cout<<num1<<num2<<endl;


    return 0;
}

void swap1(int a,int b)
{
    int temp=a;
    a=b;
    b=temp;
}
//原理
//p1 0x3=0x1
//p2 0x4=0x2
void swap2(int *p1,int *p2)
{
    //temp 0x5 = 0x1
    int temp = *p1;
    //0x1=0x2
    *p1= *p2;
    //0x2=0x1
    *p2=temp;
//    int *temp = p1;
//    printf("%d\n",*temp);
//    p1=p2;
//    p2=temp;
//    printf("%d-%d\n",*p1,*p2);
}

void swap3(int &r1,int &r2)
{
    int temp = r1;
    r1=r2;
    r2=temp;
}