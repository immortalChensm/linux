//
// Created by Administrator on 2020/4/19.
//

#include <iostream>
#include <string>
//静态成员  位于内存全局数据局
//静态成员：只有一个内存|必须初始化|可以通过对象或是类访问|程序结束时才释放内存|所有的对象都共享它

using namespace std;

class Person
{
private:
    char *name;
    int age;
    static int total;//静态成员只属于类  不任何任何东西  有单独的存储空间 位于全局数据区
public:
    Person(char *name,int age);//声明
    void show() const;
};
//定义
int Person::total=0;
//定义
Person::Person(char *name, int age) {
    this->name = name;
    this->age = age;
    //total++;
    this->total++;
}
void Person::show() const {
   // cout<<this->name<<this->age<<"total people:"<<total<<endl;
    //cout<<this->name<<this->age<<"total:"<<Person::total<<endl;
    cout<<this->name<<this->age<<"total:"<<this->total<<endl;
}

int main()
{
    (new Person((char*)"jack",20))->show();
    (new Person((char*)"tom",30))->show();
    (new Person((char*)"lucy",19))->show();

    return 0;
}