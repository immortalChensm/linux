//
// Created by Administrator on 2020/5/5.
//

#include <iostream>
#include <typeinfo>
using namespace std;
//typeid 运算符：获取类型信息
class Base{};
struct Stu{};

class Student:public Base{};
int main()
{
    int n=100;

//    const type_info &nInfo = typeid(n);
//
//    //cout<<nInfo.name()<<nInfo.raw_name()<<nInfo.hash_code()<<endl;
//    cout<<nInfo.name()<<"|"<<nInfo.hash_code()<<endl;
//
//    const type_info &dInfo = typeid(25.55);
//    cout<<dInfo.name()<<"|"<<dInfo.hash_code()<<endl;
//
//    Base obj;
//    const type_info &objInfo = typeid(obj);
//    cout<<objInfo.name()<<"|"<<objInfo.hash_code()<<endl;
//
//    const type_info &baseInfo = typeid(Base);
//    cout<<baseInfo.name()<<"|"<<baseInfo.hash_code()<<endl;
//
//    const type_info &stuInfo = typeid(struct Stu);
//    cout<<stuInfo.name()<<"|"<<stuInfo.hash_code()<<endl;
//
//    const type_info &charInfo = typeid(char);
//    cout<<charInfo.name()<<"|"<<charInfo.hash_code()<<endl;
//
//    const type_info &expInfo = typeid(20*100/46);
//    cout<<expInfo.name()<<"|"<<expInfo.hash_code()<<endl;
//
//    cout<<(typeid(int)== typeid(int))<<endl;
//
//    cout<<(typeid(char)== typeid(int))<<endl;
//
//    cout<<(typeid(char)== typeid("hello"))<<endl;
//    cout<<(typeid(char)== typeid('a'))<<endl;
//
//    cout<<(typeid(Base)== typeid(obj))<<endl;

    Base obj1;
    Base *p1;
    Student obj2;
    Student *p2 = new Student;
    p1=p2;

    cout<<(typeid(obj1)== typeid(p1))<<endl;
    cout<<(typeid(obj1)== typeid(*p1))<<endl;
    cout<<(typeid(&obj1)== typeid(p1))<<endl;
    return 0;
}