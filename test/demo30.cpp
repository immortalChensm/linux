//
// Created by Administrator on 2020/4/19.
//

#include <iostream>
#include <string>
/**
 * 静态成员变量  为全局变量
 * 静态成员函数  为全局函数
 *
 * 普通成员函数：在编译时成为全局函数，但会隐式传递当前对象的地址参数this 可以调用类中所有成员
 * 静态成员函数：在统时也成为全局函数，但是并没有传递参数 只能调用类中静态成员
 */
using namespace std;

class Person
{
private:
    int m_age;
    char *m_name;
private:
    static int total;
public:
    Person(int age,char *name);
    Person *show();

public:
    static int getTotal();
    static void talk();
};

//定义此参数是全局变量
int Person::total=0;

void Person::talk() {
    cout<<"ok"<<endl;
}



Person::Person(int age, char *name):m_age(age),m_name(name) {
    this->total++;
}

Person *Person::show() {
    cout<<this->m_name<<this->m_age;
   // cout<<"total-"<<total<<endl;
    cout<<"="<<this->total;
    //this->talk();
    return this;
}
int Person::getTotal() {
    //show(); 在静态函数中不能调用对象的show方法  本静态函数 是一个全局函数【编译时】但并没有传递当前对象this隐式参数是不可以访问对象的普通成员的
    //cout<<m_name<<endl;
    //this->talk(); 不可以
    //talk();
    return Person::total;
}
int main()
{

    (new Person(1000,(char*)"jack"))->show();
    (new Person(2000,(char*)"tom"))->show();
    (new Person(3000,(char*)"lucy"))->show()->getTotal();

    int total = Person::getTotal();
    cout<<"total="<<total<<endl;

    return 0;
}