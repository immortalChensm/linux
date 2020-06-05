//
// Created by Administrator on 2020/6/5.
//

#include <iostream>
#include <string>
#include <stdio.h>
//重定向输入输出
using namespace std;

int main()
{

    string name,url;
    //读取文件的内容并写入stdin
    freopen("../in.txt","r",stdin);
    cin>>name>>url;

    //从标准输出设备读取内容写入文件
    freopen("out.txt","w",stdout);
    cout<<name<<"\n"<<url;


    return 0;
}