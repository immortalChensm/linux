//
// Created by Administrator on 2020/5/29.
//

#include <iostream>
using namespace std;
//转换构造函数：是将其它类型转换为当前类 赋值时
//类型转换函数：是将当前类转换为其它类
class Complex
{
public:
    Complex(double real=0.0,double imag=0.0):m_real(real),m_imag(imag){}

public:
    friend ostream & operator<<(ostream &out,Complex &c);
    friend Complex operator+(const Complex &c1,const Complex &c2);
    operator double()const { return m_real;}
private:
    double m_real;
    double m_imag;
};

ostream & operator<<(ostream &out,Complex &c)
{
    out<<c.m_real<<"+"<<c.m_imag<<"i";
    return out;
}

Complex operator+(const Complex &c1,const Complex &c2)
{
    Complex c;
    c.m_real=c1.m_real+c2.m_real;
    c.m_imag=c1.m_imag+c2.m_imag;
    return c;
}

int main()
{
    Complex c1(24.6,100);

    double f = c1;//类型转换函数

    cout<<f<<endl;

    c1 = 78.4;//转换构造函数

    cout<<c1<<endl;//operator<<()
    //f = 12.5+c1; //有可能先将12.5转换为complex类型  或是先将c1转换为double 编译器不知道

    //Complex c2 = c1+46.7;

    return 0;
}