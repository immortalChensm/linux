//
// Created by Administrator on 2020/5/21.
//

#include <iostream>
#include <string>
#include <exception>
//异常规范
using namespace std;
//限定抛出的异常只能是char int无法检测到，也就无法捕获到了
void func()throw (char *,exception){
    throw 123;
    cout<<"error"<<endl;
}

int main()
{
    try{
        func();
    }catch(int){
        cout<<"exception type:int"<<endl;
    }
    return 0;
}