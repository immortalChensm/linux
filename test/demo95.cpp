//
// Created by Administrator on 2020/5/18.
//

#include <iostream>
#include <string>

using namespace std;
class B;
template<class T>
class Tmpl{
public:
    int a;
    int b;
public:
    friend void Func();
    friend class A;
    friend void B::Func(Tmpl *t);
};

void Func1()
{

}

class A{};
class B{
public:
    char c;
public:
    void Func(Tmpl *t){
        cout<<t->a<<t->b<<this.c<<endl;
    }
};



int main()
{
    Tmpl<int> i;
    i.a=100;
    i.b=200;


    Func1();
    return 0;
}