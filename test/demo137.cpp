//
// Created by Administrator on 2020/6/9.
//

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    const char *url = "www.ifeng.com";

    ofstream destFile("out.txt",ios::out);

    if(!destFile){
        cout<<"open fail"<<endl;
        return 0;
    }

    destFile<<url;

    destFile.close();

    return 0;
}