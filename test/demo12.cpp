//
// Created by Administrator on 2020/4/14.
//

#include <iostream>
#include <string>
//函数重载 Function Overloading

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