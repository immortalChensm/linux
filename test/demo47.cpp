//
// Created by Administrator on 2020/4/22.
//

#include <iostream>

using namespace std;

class Base
{
    void show();
public:
    void func();
    void func(int);
};
void Base::func() {
    cout<<"base::func"<<endl;
}
void Base::func(int) {
    cout<<"base::func(int)"<<endl;
}
void Base::show() {
    cout<<"base::show"<<endl;
}

class Derived:public Base
{
public:
    void func(char *);
    void func(bool);
};
void Derived::func(char *) {
    cout<<"derived::func(char*)"<<endl;
}
void Derived::func(bool is) {
    cout<<"derived::func(bool)"<<endl;
}

int main()
{
    Derived d;

    d.func((char*)"a");
    d.func(true);
    //d.func();
    d.Base::func();
    d.Base::func(100);

    //d.show();

    int a = 10;//0000 1010 0000 0101
    cout<<(a>>1)<<endl;

    return 0;
}