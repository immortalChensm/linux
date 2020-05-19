//
// Created by Administrator on 2020/5/19.
//

#include <iostream>
#include <string>

using namespace std;
class A;


class A{
public:
    A(int a,char b):m_a(a),m_b(b){};

public:
    void show(){
        cout<<this->m_a<<this->m_b<<endl;
    }
    friend void talk(A *obj);
    friend class B;

public:
    A &operator+=(A &obj){
        this->m_a=this->m_a+obj.m_a;
        return *this;
    }
    ostream &operator<<(A &obj){
        cout<<"a="<<this->m_a<<"obj:a="<<obj.m_a;
        return cout;
    }
public:
    int m_a;
    char m_b;
};
void talk(A *obj)
{
    cout<<"i am talking\n";
    obj->show();
}
class B{
public:
    void show(A &obj);
};
void B::show(A &obj) {
    cout<<"A::a="<<obj.m_a<<",A::b="<<obj.m_b<<endl;
}
ostream &operator<<(ostream &o,A &obj){
    o<<obj.m_a;
    return o;
}
int main()
{
    A obj(100,'a');
    talk(&obj);

    B b;
    b.show(obj);

    A obj1(200,'b');

    obj+=obj1;
    obj.show();

    cout<<obj<<obj1<<endl;
    //operator<<(cout,obj)

    obj<<obj1<<endl;
    //obj.operator<<(obj1)

    return 0;
}