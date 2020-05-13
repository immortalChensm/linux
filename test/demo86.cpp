//
// Created by Administrator on 2020/5/13.
//

#include <iostream>
#include <string>

using namespace std;

typedef struct {
    string name;
    int age;
    float score;
}STU;

template <class T>const T& Max(const T &a,const T &b);
//函数模板  类型参数显示具体化
template <> const STU& Max<STU>(const STU &a,const STU &b);

ostream & operator<<(ostream &out,const STU &stu);

int main()
{
    int a = 10;
    int b=20;

    cout<<Max(a,b)<<endl;
    cout<<Max<int>(a,b)<<endl;

    STU stu1 = {"jack",16,2.2};
    STU stu2 = {"tom",20,42.5};
    cout<<Max<STU>(stu1,stu2)<<endl;

    return 0;
}

template <class T>const T & Max(const T &a,const T &b)
{
    return a>b?a:b;
}
template <> const STU & Max<STU>(const STU &a,const STU &b)
{
    return a.score>b.score?a:b;
}

ostream & operator<<(ostream &out,const STU &stu)
{
    out<<stu.name<<","<<stu.age<<","<<stu.score;
    return out;
}