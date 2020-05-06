//
// Created by Administrator on 2020/5/6.
//

#include <iostream>
#include <string>
//运算符全局函数
using namespace std;

class complex
{
public:
    complex();
    complex(double real,double imag);

public:
    void display() const;
    //友元函数
    //此函数将能访问本类的成员
    //friend声明为友元函数
    //complex 返回值类型
    //operator+函数名称
    //()参数列表
    //const complex &A A是一个引用【指针的封闭】 的complex数据类型
    friend complex operator+(const complex &A,const complex &B);

private:
    double m_real;
    double m_imag;
};

//全局函数声明
complex operator+(const complex &A,const complex &B);

//complex构造函数重载的初始化列表
complex::complex():m_real(0.0),m_imag(0.0) {}
complex::complex(double real, double imag):m_real(real),m_imag(imag) {}
void complex::display() const {
    cout<<m_real<<"+"<<m_imag<<"i"<<endl;
}

//全局函数定义
//返回值类型为complex
//operator+函数名
complex operator+(const complex &A,const complex &B){
    complex C;
    C.m_real = A.m_real+B.m_real;
    C.m_imag = A.m_imag+B.m_imag;

    return C;
}

int main()
{
    complex c1(4.3,5.8);
    complex c2(2.4,3.7);
    complex c3;

    c3 = c1+c2;
    c3.display();

    return 0;
}