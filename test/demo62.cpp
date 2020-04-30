//
// Created by Administrator on 2020/4/30.
//

#include <iostream>
#include <string>
//c++多态  虚函数
//虚函数  构成多态
//借助虚函数构成多态
//c++中的成员函数调用：对象的数据类型【类】是啥就调用谁【类】的成员函数
//c++中的虚成员函数调用：对象的地址是谁【类】是啥就调用谁【类的】的成员函数
using namespace std;

class People{
public:
    People(char *name,int age);
    virtual void display();

protected:
    char *m_name;
    int m_age;
};
People::People(char *name, int age):m_name(name),m_age(age) {}
void People::display() {
    cout<<m_name<<m_age<<endl;
}

class Teacher:public People
{
public:
    Teacher(char *name,int age,int salary);
    virtual void display();

private:
    int m_salary;
};
Teacher::Teacher(char *name, int age, int salary):People(name,age),m_salary(salary) {}
void Teacher::display() {
    cout<<m_name<<m_age<<m_salary<<endl;
}

int main()
{
    People *p = new People((char*)"tom",20);
    p->display();

    //向下转型  teacher类的对象实例的第一个成员地址是和people类的实例第一个成员地址是一样的
    //但是，p的数据类型是people类，并不是teacher类
    //而display是一个全局函数，在编译时，传递的隐匿参数是teacher，但是类型是people
    p = new Teacher((char*)"jack",18,100000);
    p->display();



    return 0;
}