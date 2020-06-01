//
// Created by Administrator on 2020/6/1.
//

#include <iostream>

using namespace std;

class A
{
public:
    A(int a=0,int b=0):m_a(a),m_b(b){}
private:
    int m_a;
    int m_b;
};

int main()
{
    char str[] = "http://www.baidu.com";
    float *p1 = reinterpret_cast<float*>(str);
    cout<<*p1<<endl;

    int *p = reinterpret_cast<int*>(100);

    p = reinterpret_cast<int*>(new A(25,100));
    cout<<*p<<endl;
    return 0;
}