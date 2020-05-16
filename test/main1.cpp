//
// Created by Administrator on 2020/5/16.
//

#include <iostream>
#include "func1.h"
#include "point.h"
//模板实例化
//由模板生成函数或是类的过程
//特定数据类型生成的函数或是类称为模板的一个实例

//模板显示实例化
//直接告诉编译器  要生成的函数【数据类型】
using namespace std;

//显示指明模板要生成double,int,char类型的函数
extern template void Swap(double &a,double &b);
extern template void Swap(int &a,int &b);
extern template void Swap(char &a,char &b);

//类模板的  模板显示实例化
//自己知道要用哪些数据类型可以使用模板显示实例化，提供给别人用的库根本不知道别人要用什么
extern template class Point<char *,char *>;
extern template class Point<int,int>;
int main()
{
    int n1=10,n2=100;

    Swap(n1,n2);

    cout<<n1<<n2<<endl;

    double f1=23.8,f2=92.66;
    Swap(f1,f2);

    cout<<f1<<f2<<endl;

    char a='a',b='b';
    Swap<char>(a,b);
    cout<<a<<b<<endl;

    Point<int,int> p1(10,20);
    p1.setY(100);
    p1.setX(300);
    p1.display();
    cout<<"x="<<p1.getX()<<",y="<<p1.getY()<<endl;

    Point<char *,char *> p2((char*)"180",(char*)"120");
    p2.display();


    Point<char *,char *> *p3 = new Point<char*,char *>((char*)"10",(char*)"60");
    p3->display();
    return 0;
}