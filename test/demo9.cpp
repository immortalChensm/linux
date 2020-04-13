//
// Created by Administrator on 2020/4/13.
//

#include <iostream>
#include <string>
//内联函数  类似C的宏替换
using namespace std;

inline void display(string str)
{
    cout<<str<<endl;
}
int main()
{

    display("hello,world");
    cout<<(1<<2&1<<3|0b1100&8)<<endl;//0001 0100
                                   //0001 1000
                                   //     1100
                                   //     1000
    return 0;
}