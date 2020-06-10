//
// Created by Administrator on 2020/6/10.
//

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int x,sum=0;

    ifstream srcFile("in.txt",ios::in|ios::binary);
    if (!srcFile){
        cout<<"error opening source file."<<endl;
        return 0;
    }

    ofstream destFile("out.txt",ios::out|ios::binary);
    if (!destFile){
        srcFile.close();
        cout<<"error opening destination file."<<endl;
        return 0;
    }
    //调用srcFile.operator>>(x) 读取文件的内容
    while(srcFile>>x){
        sum+=x;
        //调用destFile.operator<<(x) 写入文件内容
        destFile<<x<<" ";

    }

    cout<<"sum:"<<sum<<endl;

    destFile.close();
    srcFile.close();
    return 0;
}