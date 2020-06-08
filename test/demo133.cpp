//
// Created by Administrator on 2020/6/6.
//

#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>
using namespace std;

struct a{
    int m_h;
    int m_w;
};
class demo:public a
{
public:
    demo(){
        this->m_w=100;
        this->m_h=200;
    }
public:
    int m_age;
    char m_address[32];//16+32
    int m_score;
};
int main()
{

    a c = {80,90};
    demo a;
    demo *b = &a+ sizeof(c);
    b->m_score=1;
    b->m_age=18;
    strcpy(b->m_address,(char*)"beijing");

    cout<< sizeof(a)<<endl;

    cout<<a.m_h<<a.m_w<<endl;
    cout<<b->m_h<<b->m_w<<endl;


    return 0;
}