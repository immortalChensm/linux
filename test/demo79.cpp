//
// Created by Administrator on 2020/5/8.
//

#include <iostream>
//函数模板
using namespace std;

template <typename T>void Swap(T *a,T *b)
{
    T temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int n1=100,n2=200;
    Swap(&n1,&n2);

    cout<<n1<<","<<n2<<endl;

    float f1=12.42,f2=42.56;
    Swap(&f1,&f2);
    cout<<f1<<f2<<endl;

    char c1='a',c2='b';
    Swap(&c1,&c2);
    cout<<c1<<c2<<endl;

    //c 0x01 =100
    int c=100;
    cout<<c<<(*&c)<<endl;
    //0x01=100


    return 0;
}