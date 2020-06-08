//
// Created by Administrator on 2020/6/8.
//

#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

int main()
{
    const char *url = "www.baidu.com";

    fstream fs;

    //fs.open("test.txt",ios::out);
    //fs.write(url,strlen(url));
    //fs.close();

    fs.open("test.txt",ios::in);
    char data[30]={};
    fs.read(data,30);

    cout<<data<<endl;
    fs.close();

    return 0;
}