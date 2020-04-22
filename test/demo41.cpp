//
// Created by Administrator on 2020/4/22.
//

#include <iostream>
#include <string>

using namespace std;

int main()
{
    int m=10;
    int n=10;

    int *p = &(m+n);//获取寄存器的地址  无法获取
    return 0;
}