//
// Created by Administrator on 2020/5/7.
//

#include <iostream>
#include <string>

using namespace std;
class Complex
{
public:
    Complex():m_real(0.0),m_imag(0.0){}
    Complex(double real,double imag):m_real(real),m_imag(imag){}
    //转换构建函数：构造+转换
    Complex(double real):m_real(real),m_imag(0.0){}

public:
    friend Complex operator+(const Complex &c1,const Complex &c2);

public:
    double real()const{return m_real;}
    double image() const { return m_imag;}

private:
    double m_real;
    double m_imag;
};

Complex operator+(const Complex &c1,const Complex &c2)
{
    Complex c;
    c.m_real=c1.m_real+c2.m_real;
    c.m_imag=c1.m_imag+c2.m_imag;
    return c;
}

int main()
{
    Complex c1(25,35);

    Complex c2 = c1+15.6;
    //转换如下
    //operator+函数
    //28.23自动转换为Complex对象
    //c2=operator+(c1,Complex(15.6))
    //如果operator+重载函数是类的成员则是
    //c1.operator+(Complex(15.6))
    Complex c3 = 28.23+c1;
    //全局+运算符重载函数：c3=operator+(Complex(28.23),c1)
    //类成员+运算符重载函数时：c3=(28.23).operator+(c1)

    cout<<c2.real()<<"+"<<c2.image()<<"i\n";
    cout<<c3.real()<<"+"<<c2.image()<<"i\n";

    return 0;
}