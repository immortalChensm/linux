//
// Created by Administrator on 2020/5/27.
//

#include <iostream>
using namespace std;

class Complex{
public:
    Complex(double real=0.0,double imag=0.0):m_real(real),m_imag(imag){}
    //构造函数  可实现类型转换【类型转换构造函数】
public:
    friend ostream &operator<<(ostream &out,Complex &c);
private:
    double m_real;
    double m_imag;
};

ostream & operator<<(ostream &out,Complex &c){
    out<<c.m_real<<"+"<<c.m_imag<<"i";
    return out;
}

int main()
{
    Complex a(10.0,20.0);
    Complex b(21);

    Complex c;
    a=23.5;

    cout<<a<<b<<c<<endl;
}