//
// Created by Administrator on 2020/6/13.
//

#include <iostream>
#include "Stu.h"
#include <string.h>
using namespace std;
void Stu::initStu(int number, char* name)
{
    _number = number;
    strcpy(_name, name);

    initScore(12345);

    cout <<"score="<< score << endl;
}

void Stu::initScore(int s) {
    score = s;
}

Stu::Stu(int number, char* name)
{
    _number = number;
    strcpy(_name, name);
}