//
// Created by Administrator on 2020/6/9.
//

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream fs;
    fs.open("out2.txt",ios::out);

    fs<<"hello,world";

    fs.flush();

    throw "exception";

    fs.close();
    return 0;
}