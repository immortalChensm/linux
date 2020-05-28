//
// Created by Administrator on 2020/5/28.
//
#include <iostream>
using namespace std;
//类型转换函数
/**
 * 普通函数
 * 静态函数
 * 构造函数
 *      初始构造函数  无参数
 *      普通构造函数  有参数
 *      拷贝构造函数  有一个参数
 *      转换构造函数  有一个参数 有参数且有默认值
 * 析构函数
 * 友元函数
 * 虚函数
 * 函数/成员遮蔽
 * 类型转换函数 operator type()
 * 重载函数
 */
class Complex
{
public:
    Complex():m_real(0.0),m_imag(0.0){}
    Complex(double real,double imag):m_real(real),m_imag(imag){}

public:
    friend ostream &operator<<(ostream &out,Complex &c);
    friend Complex operator+(const Complex &c1,const Complex &c2);
    operator double() const { return m_real;}//类型转换函数
    //operator int()const { return m_imag;} 容易歧义
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

    Complex c1(25.6,100);
    double f = c1;//调用Complex::operator double(&c1);

    cout<<"f = "<<f<<endl;

    f = 12.5+c1+6;//f=12.5+Complex::operator double(&c1)+6

    cout<<"f = "<<f<<endl;

    int n = Complex(43.2,9.3);//n = Complex::operator double(this)
    cout<<"n="<<n<<endl;



    return 0;
}