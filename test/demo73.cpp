//
// Created by Administrator on 2020/5/7.
//

#include <iostream>
#include <string>
#include <math.h>
//数学运算符重载
using namespace std;

class Complex{
public:
    //构造函数+初始化列表+形式参数默认值
    Complex(double real=0.0,double imag=0.0):m_real(real),m_imag(imag){}

public:
    //友元全局函数声明处
    //数学运算符重载函数
    friend Complex operator+(const Complex &c1,const Complex &c2);
    friend Complex operator-(const Complex &c1,const Complex &c2);
    friend Complex operator*(const Complex &c1,const Complex &c2);
    friend Complex operator/(const Complex &c1,const Complex &c2);
    friend bool operator==(const Complex &c1,const Complex &c2);
    friend bool operator!=(const Complex &c1,const Complex &c2);

    //成员函数  返回值类型为Complex &
    Complex &operator+=(const Complex &c);
    Complex &operator-=(const Complex &c);
    Complex &operator*=(const Complex &c);
    Complex &operator/=(const Complex &c);

public:
    double real() const { return m_real;}
    double imag() const { return m_imag;}
private:
    double m_real;
    double m_imag;
};

Complex operator+(const Complex &c1,const Complex &c2){
    Complex c;
    c.m_real = c1.m_real+c2.m_real;
    c.m_imag = c1.m_imag+c2.m_imag;
    return c;
}
Complex operator-(const Complex &c1,const Complex &c2){
    Complex c;
    c.m_real = c1.m_real-c2.m_real;
    c.m_imag = c1.m_imag-c2.m_imag;
    return c;
}
Complex operator*(const Complex &c1,const Complex &c2)
{
    Complex c;
    c.m_real = c1.m_real*c2.m_real-c1.m_imag*c2.m_imag;
    c.m_imag = c1.m_imag*c1.m_real+c1.m_real*c2.m_imag;
    return c;
}
Complex operator/(const Complex &c1,const Complex &c2)
{
    Complex c;
    c.m_real=(c1.m_real*c2.m_real+c1.m_imag*c2.m_imag)/(pow(c2.m_real,2)+pow(c2.m_imag,2));
    c.m_imag=(c1.m_imag*c2.m_real-c1.m_real*c2.m_imag)/(pow(c2.m_real,2)+pow(c2.m_imag,2));
    return c;
}

bool operator==(const Complex &c1,const Complex &c2)
{
    if (c1.m_real==c2.m_real&&c1.m_imag==c2.m_imag){
        return true;
    }else{
        return false;
    }
}

bool operator!=(const Complex &c1,const Complex &c2)
{
    if (c1.m_real!=c2.m_real||c1.m_imag!=c2.m_imag){
        return true;
    }else{
        return false;
    }
}

Complex & Complex::operator+=(const Complex &c) {
    this->m_real+=c.m_real;
    this->m_imag+=c.m_imag;
    return *this;
}
Complex& Complex::operator-=(const Complex &c) {
    this->m_real-=c.m_real;
    this->m_imag-=c.m_imag;
    return *this;
}

Complex& Complex::operator*=(const Complex &c) {
    this->m_real=this->m_real*c.m_real-this->m_imag*c.m_imag;
    this->m_imag=this->m_imag*c.m_real+this->m_real*c.m_imag;
    return *this;
}

Complex& Complex::operator/=(const Complex &c) {
    this->m_real=(this->m_real*c.m_real+this->m_imag*c.m_imag)/(pow(c.m_real,2)+pow(c.m_imag,2));
    this->m_imag=(this->m_imag*c.m_real-this->m_real*c.m_imag)/(pow(c.m_real,2)+pow(c.m_imag,2));
    return *this;
}

int main()
{
    Complex c1(25,35);
    Complex c2(10,20);
    Complex c3(1,2);
    Complex c4(4,9);
    Complex c5(34,6);
    Complex c6(80,90);

    Complex c7 = c1+c2;
    Complex c8 = c1-c2;
    Complex c9 = c1*c2;
    Complex c10 = c1/c2;

    cout<<"c7="<<c7.real()<<"+"<<c7.imag()<<"i"<<endl;

    c3+=c1;
    cout<<"c3="<<c3.real()<<"+"<<c3.imag()<<"i"<<endl;

    if (c1==c2){
        cout<<"c1==c2"<<endl;
    }else{
        cout<<"c1!=c2\n";
    }
    return 0;
}