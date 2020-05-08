//
// Created by Administrator on 2020/5/8.
//

#include <iomanip>
#include <iostream>
/**
 * int *a 只能传递地址  不可以传递普通数据
 * a 0x01 0x11
 * b 0x02 0x22
 * @param a
 * @param b
 */
void Swap(int *a, int *b){
    //temp 0x03 = 1
    int temp = *a;
    //0x11=2
    *a = *b;
    //0x22=1
    //b=temp  0x02=1
    *b = temp;
}

int main()
{
    return 0;
}