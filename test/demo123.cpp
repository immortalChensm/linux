//
// Created by Administrator on 2020/6/1.
//

#include <iostream>
#include <iomanip>

using namespace std;

class Base{
public:
    Base(int a=0):m_a(a){}
    int get_a()const { return m_a;}
    virtual void func() const{}
protected:
    int m_a;
};

class Derived:public Base{
public:
    Derived(int a=0,int b=0):Base(a),m_b(b){}
    int get_b()const { return m_b;}

private:
    int m_b;
};

int main()
{

    Derived *pd1 = new Derived(35,100);
    Base *pd1 = dynamic_cast<Derived*>(pd1);

    cout<<"pd1="<<pd1<<",pd1="<<pd1<<endl;

    cout<<pd1->get_a()<<endl;

    pd1->func();

    return 0;
}