//
// Created by Administrator on 2020/4/14.
//

#include <iostream>
#include <string>
//函数重载 Function Overloading
//在编译时，编译器依然会修改Swap函数为_Swap_int_int _Swap_char_char 为不同的函数

using namespace std;

void Swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void Swap(char *a,char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}
int main()
{
    int a=10,b=20;
    Swap(&a,&b);
    cout<<a<<b<<endl;

    char a1='A',b1='B';
    Swap(&a1,&b1);
    cout<<a1<<b1<<endl;

    Swap(&a,&b);
    cout<<a<<b<<endl;

    return 0;
}