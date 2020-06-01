//
// Created by Administrator on 2020/6/1.
//

#include <iostream>
#include <cstdlib>
//数据类型转换
using namespace std;

class Complex
{
public:
    Complex(double real=0.0,double imag=0.0):m_real(real),m_imag(imag){}

public:
    operator double() const { return this->m_real;}
private:
    double m_real;
    double m_imag;
};

int main()
{
    int m = 100;
    Complex c(12.5,23.8);

    long n = static_cast<long>(m);

    cout<<n<<endl;
    char ch = static_cast<char>(m);
    cout<<"ch="<<ch<<endl;
    int *p1 = static_cast<int*>(malloc(10* sizeof(int)));
    printf("p1=%#X\n",p1);
    void *p2 = static_cast<void*>(p1);
    printf("p2=%#x\n",p2);
    double real = static_cast<double>(c);
    printf("real=%f\n",real);

    //float *p3 = static_cast<float*>(p1);
    //p3 = static_cast<float*>(0X2DF9);

    return 0;
}