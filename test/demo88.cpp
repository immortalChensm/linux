//
// Created by Administrator on 2020/5/13.
//

#include <iostream>
#include <string>

using namespace std;

typedef struct {
    string name;
    int age;
}ABC;

template <typename T1>const T1 add(const T1 &a,const T1 &b);
template <> const ABC add<ABC>(const ABC &a,const ABC &b);

ostream & operator<<(ostream &out,ABC &arg);


int main()
{

    ABC jack = {"jack",20};
    ABC tom = {"tom",23};

    ABC total = add<ABC>(jack,tom);
    cout<<total<<total<<endl;

    int a=100;
    float b=100.32;
    int c = add<int>(a,b);
    cout<<c<<endl;
    return 0;
}

template <typename T1>const T1 add(const T1 &a,const T1 &b)
{
    //cout<<a<<b<<endl;

    T1 c=a+b;

    return c;
}
template <> const ABC  add<ABC>(const ABC &a,const ABC &b)
{
    ABC temp={"temp",100};
    temp.age=a.age+b.age;
    //cout<<temp.age<<endl;
    return temp;
}

ostream & operator<<(ostream &out,ABC &arg){
    out<<arg.name<<arg.age;
    return out;
}