//
// Created by Administrator on 2020/6/4.
//

#include <iostream>
#include <fstream>
#include <string.h>
#include <typeinfo>
using namespace std;

int main()
{
    ofstream outfile;

    cout<< typeid(outfile).name()<<endl;
    cout<< typeid(ostream).name()<<endl;

    //cout<<typeof(outfile)<<endl;


    outfile.open("test1.txt");

    const char *str = "www.baidu.com";
    for (int i = 0; i <strlen(str) ; ++i) {

        outfile.put(str[i]);
    }

    cout<<"current pos:"<<outfile.tellp()<<endl;

    outfile.seekp(4);

    cout<<"new pos:"<<outfile.tellp()<<endl;

    outfile.write("ifeng",5);

    outfile.close();
    return 0;
}