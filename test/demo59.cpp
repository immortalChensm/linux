//
// Created by Administrator on 2020/4/29.
//

#include <iostream>
#include <string>

using namespace std;

class A{
public:
    int a1;
    int a2;
};
class B:virtual public A{
public:
    int b1;
    int b2;
};
class C:virtual public B{
public:
    int c1;
    int c2;
};
class D:public C{
public:
    int d1;
    int d2;
};

int main()
{
    A a1;
    B b1;
    C c1;
    D d1;

    printf("%#x,%#x,%#x,%#x,%#x,%#x,%#x,%#x",&(d1.a1),&(d1.a2),&(d1.b1),&(d1.b2),&(d1.c1),&(d1.c2),&(d1.d1),&(d1.d2));
    return 0;
}