//
// Created by Administrator on 2020/4/29.
//

#include <iostream>
#include <string>
//c++的多继承之虚基类，虚继承
//开发过程中不建议使用多继承
using namespace std;

class A{
protected:
    int m_a;
};
class B:virtual public A{
protected:
    int m_b;
};

class C:virtual public A{
protected:
    int m_c;
};

class D:public B,public C{
private:
    int m_d;
public:
    void seta(int a)
    {
        this->m_a=a;
    }
    void show(){
        cout<<this->m_a<<endl;
    }
};

int main()
{
    D d;
    d.seta(1000);
    d.show();
    return 0;
}