//
// Created by Administrator on 2020/5/25.
//

#include <iostream>
#include <string>
//浅拷贝和深拷贝
using namespace std;

class Base{
public:
    Base():m_a(0),m_b(0){}
    Base(int a,int b):m_a(a),m_b(b){}
    Base(const Base &b);

public:
    void display();
private:
    int m_a;
    int m_b;
};
Base::Base(const Base &b) {
    this->m_b=b.m_b;
    this->m_a=b.m_a;
}
void Base::display() {
    cout<<m_a<<m_b<<endl;
}
int main()
{
    int a=10;
    int b=a;

    Base obj1(10,20);

    obj1.display();
    Base obj2 = obj1;
    obj2.display();

    Base *obj3 = new Base(100,200);
    obj3->display();

    delete [] obj3;

    Base *obj4[] = {new Base(10,30),new Base};
    obj4[0]->display();
    obj4[1]->display();

    delete [] obj4[0];
    delete [] obj4[1];

    cout<<"*****************"<<endl;

    Base obj5[2] = {{1,2},{3,4}};
    obj5[0].display();
    obj5[1].display();


    Base obj6(obj5[0]);

    obj6.display();

    Base obj7 = obj5[1];
    obj7.display();
    return 0;
}