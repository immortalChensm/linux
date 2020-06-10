//
// Created by Administrator on 2020/6/10.
//

#include <iostream>
#include <fstream>

using namespace std;
//以二进制形式读写文件
class CStudent
{
public:
    char szName[20];
    int age;
};

int main()
{
    CStudent s;
    ofstream outFile("students.dat",ios::out|ios::binary);
    while (cin>>s.szName>>s.age){
        outFile.write((char*)&s, sizeof(s));
    }
    outFile.close();
    return 0;
}