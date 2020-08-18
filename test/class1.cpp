//
// Created by Administrator on 2020/8/12.
//

#include <iostream>
#include <string>

using namespace std;

class A{
public:
    int i;
    A()
    {
        cout<<"A"<<endl;
    }
    virtual ~A(){
        //show();
        cout<<"~A"<<endl;
    }

     void show()
    {
        cout<<2<<endl;
    }
};

class B:public A{
public:
    int j;
    B()
    {
        cout<<"B"<<endl;
    }
    ~B(){
        cout<<"~B"<<endl;
    }
    void show()
    {
        A::show();
        cout<<1<<endl;
    }
};
int main()
{

    B *obj = new B();

    obj->show();
    delete obj;


    return 0;
}