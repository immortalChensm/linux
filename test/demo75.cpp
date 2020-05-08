//
// Created by Administrator on 2020/5/8.
//

#include <iostream>
#include <string>
//<< >>运算符重载
using namespace std;

class complex
{
public:
    complex(double real=0.0,double imag=0.0):m_real(real),m_imag(imag){}

public:
    friend istream &operator>>(istream &in,complex &A);
    friend ostream &operator<<(ostream &out,complex &A);
    friend complex operator+(const complex &A,const complex &B);

private:
    double m_real;
    double m_imag;
};

complex operator+(const complex &A,const complex &B){
    complex C;
    C.m_real=A.m_real+B.m_real;
    C.m_imag = A.m_imag+B.m_imag;
    return C;
}

istream & operator>>(istream &in,complex &A)
{
    in>>A.m_real>>A.m_imag;
    return in;
}
ostream & operator<<(ostream &out,complex &A)
{
    out<<A.m_real<<"+"<<A.m_imag<<"i";;
    return out;
}

int main()
{
    complex c1,c2,c3;
    cin>>c1>>c2;
    //operator>>(cin,c1)->(cin,c2)

    c3=c1+c2;
    //operator+(c1,c2)
    cout<<"c1+c2="<<c3<<endl;
    //operator<<(cout,c3)

    return 0;
}