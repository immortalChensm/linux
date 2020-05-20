//
// Created by Administrator on 2020/5/20.
//

#include <iostream>
#include <string>
#include <exception>

using namespace std;

void func()
{
    //throw "unknow Exception";
    throw 123;
    cout<<"will not be executed."<<endl;
}

void func1()
{
    func();
    cout<<"no"<<endl;
}
int main()
{
    try{

        //func();
        func1();
        cout<<"ok"<<endl;
    }catch (int e){//const char *&e
        cout<<e<<endl;
    }

    return 0;
}