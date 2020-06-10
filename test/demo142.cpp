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

    fstream fs;
    fs.open("students.dat",ios::in|ios::binary);
    if (!fs){
        cout<<"open file error.";
        return 0;
    }

    while ((fs.read((char*)&s, sizeof(s)))){

        cout<<s.szName<<s.age<<endl;
    }

    fs.close();
    return 0;
}