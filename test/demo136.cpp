//
// Created by Administrator on 2020/6/8.
//

#include <iostream>
#include <fstream>
//文件流的打开
using namespace std;

int main()
{
    ifstream inFile("inFile1.txt",ios::in);
    if (inFile){
        inFile.close();
    }else{
        cout<<"inFile1.txt doesn't exist"<<endl;
    }

    ofstream oFile("oFile1.txt",ios::out);
    if (!oFile){
        cout<<"error 1";
    }else{
        oFile.close();
    }

    fstream oFile1("oFile2.txt",ios::out|ios::in|ios::trunc);
    if (!oFile1){
        cout<<"error 2";
    }else{
        oFile1.close();
    }

    return 0;
}