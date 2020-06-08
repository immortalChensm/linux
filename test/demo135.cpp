//
// Created by Administrator on 2020/6/8.
//

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream inFile;
    inFile.open("inFile.txt",ios::in);
    if (inFile){
        inFile.close();
    }else{
        cout<<"inFile.txt doesn't exist"<<endl;
    }

    ofstream oFile;
    oFile.open("oFile.txt",ios::out);
    if (!oFile){
        cout<<"error 1"<<endl;
    }else{
        oFile.close();
    }

    fstream ioFile;
    ioFile.open("ioFile.txt",ios::out|ios::in|ios::trunc);
    if(!ioFile){
        cout<<"errno 3"<<endl;
    }else{
        ioFile.close();
    }
    return 0;
}