//
// Created by Administrator on 2020/6/13.
//

#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include "Stu.h"
using namespace std;


//类的构造函数 ,explicit,初始化列表
//构造函数是类中的特殊成员函数，由系统自动调用
void initStu(Stu& s, int number, char* name)
{
    s._number = number;
    strcpy(s._name,  name);
}

int main()
{

    //stu s;
    //s.initStu(100, (char*)"lucy");
    Stu s(1000, (char*)"jack");
    cout << s._name << endl;
    return 0;
}