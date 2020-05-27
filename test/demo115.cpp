//
// Created by Administrator on 2020/5/27.
//

#include <iostream>
#include <string.h>
//转换构造函数
using namespace std;

class Complex{
public:
    Complex():m_real(0),m_imag(0){}
    Complex(double real,double imag):m_real(real),m_imag(imag){}
    Complex(double real):m_real(real),m_imag(0.0){}//转换构造函数
public:
    friend ostream&operator<<(ostream &out,Complex &c);
    Complex & operator+(Complex &obj);
private:
    double m_real;

double m_imag;
};

ostream & operator<<(ostream &out,Complex &c){
    cout<<c.m_real<<"+"<<c.m_imag;
    return out;
}

Complex & Complex::operator+(Complex &obj) {

    this->m_real+=obj.m_real;
    return *this;
}
int main()
{
    Complex a(10.0,20.0);
    cout<<a<<endl;

    a = (Complex)25.5;
    //a = 25.5;
    cout<<a<<endl;

    a = 100;
    cout<<a<<endl;
    //a = true;
   // cout<<a<<endl;

    //Complex *b = new Complex(1,2);
    Complex b(1,2);
    Complex c = 100;
    b=b+a+c;//b.opertor+(Complex(1))

    cout<<b<<endl;
    return 0;
}