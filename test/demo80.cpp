//
// Created by Administrator on 2020/5/9.
//

#include <iostream>
#include <string>

using namespace std;

template<typename T> T Max(T a,T b);

int main()
{
    int a=10;
    int b=100;
    int m = Max(a,b);
    cout<<m<<endl;

    char a1='A';
    char b1='B';
    char j = Max(a1,b1);
    cout<<j<<endl;
    return 0;
}
template<typename T>T Max(T a,T b)
{
    T max=a;
    if (a>b){
        max = a;
    }else{
        max = b;
    }
    return max;
}