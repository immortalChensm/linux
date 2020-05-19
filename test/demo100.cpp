//
// Created by Administrator on 2020/5/19.
//

#include <iostream>
#include <string>
#include <exception>
//异常
using namespace std;

int main()
{
    string str="hello,world";

    try{
        char ch = str[100];
        cout<<ch<<endl;
    }catch (exception e){
        cout<<"out of range"<<endl;
    }
    cout<<"test"<<endl;

    try{
        char ch1 = str.at(100);
        cout<<ch1<<endl;
    }catch(exception e){
        cout<<"out of range1"<<endl;
    }

    cout<<"end"<<endl;
    return 0;
}