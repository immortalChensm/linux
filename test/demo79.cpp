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

    //h=0110 1000 68
    //e=0110 0101 65
    //l=0110 1100 6c
    //o = 0110 1111
    //w=0111 0111
    //r=0111 0010
    //d=0110 0100

    cout<<(char)0b01101000<<(char)0b01100101<<(char)0b01101100<<(char)0b01101100<<(char)0b01101111<<(char)0b00101100;
    cout<<(char)0b01110111<<(char)0b01101111<<(char)0b01110010<<(char)0b01101100<<(char)0b01100100<<endl;

    //6*10=60
    int text[] = {0x68,0b01100101,0b01101100,0b01101100,0b01101111,0b00101100,0b01110111,0b01101111,0b01110010,0b01101100,0b01100100};

    for (int i = 0; i <11 ; ++i) {
        printf("%c",text[i]);
    }
    return 0;
}