//
// Created by Administrator on 2020/5/8.
//

#include <iostream>
#include <iomanip>
#include <string>
//++ 运算符重载
using namespace std;

class stopwatch{
public:
    //构建函数
    stopwatch():m_min(0),m_sec(0){}
public:
    void setzero(){m_min=0,m_sec=0;}
    //run 函数  返回值类型为stopwatch
    stopwatch run();
    //operator++ 函数  返回值类型为stopwatch
    stopwatch operator++();
    //operator++函数，可带参数  返回类型为stopwatch
    stopwatch operator++(int);
    //operator<<()函数  2个参数  返回参数为ostream & 返回的是一个ostream引用
    friend ostream &operator<<(ostream &,const stopwatch &);
private:
    int m_min;
    int m_sec;
};

stopwatch stopwatch::run() {
    ++m_sec;
    if (m_sec==60){
        m_min++;
        m_sec=0;
    }
    return *this;
}

stopwatch stopwatch::operator++() {
    return run();
}

stopwatch stopwatch::operator++(int n) {
    stopwatch s = *this;
    run();
    return s;
}
//ostream 返回的还是自己的地址
ostream &operator<<(ostream &out,const stopwatch &s)
{
    out<<setfill('0')<<setw(2)<<s.m_min<<":"<<setw(2)<<s.m_sec;
    return out;
}

int main()
{
    //栈上实例化对象
    stopwatch s1,s2;
    s1=s2++;
    //s2.operator++()
    cout<<"s1:"<<s1<<endl;
    //operator<<(cout,s1)
    cout<<"s2:"<<s2<<endl;

    s1.setzero();
    s2.setzero();

    s1=++s2;
    //s2.operator++()
    cout<<"s1:"<<s1<<endl;
    cout<<"s2:"<<s2<<endl;

    return 0;
}