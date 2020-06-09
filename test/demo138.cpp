//
// Created by Administrator on 2020/6/9.
//

#include <iostream>
#include <fstream>
//要急时调用文件流对象的close方法
using namespace std;

int main()
{
    ofstream outFile("out1.txt",ios::out);

    if (!outFile){
        cout<<"open failr"<<endl;
        return 0;
    }

    outFile<<"php is the best"<<"java is the best";
    outFile.close();
    throw "exception";


    return 0;
}