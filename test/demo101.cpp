//
// Created by Administrator on 2020/5/20.
//

#include <iostream>
#include <string>
#include <exception>
using namespace std;

int main()
{
    try{

        cout<<"prepare to throw a exception"<<endl;
        throw "Unkonw exception";
        cout<<"this statement wioo not be executed."<<endl;
    }catch (const char *&e){
        cout<<e<<endl;
    }

    return 0;
}
