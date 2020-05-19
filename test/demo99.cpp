//
// Created by Administrator on 2020/5/19.
//

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str = "http://www.baidu.com";
    printf("%d\n",str.length());

    char ch=str[50];

    cout<<ch<<endl;

    char ch2 = str.at(2);
    cout<<ch2<<endl;
    ch2 = str.at(100);
    cout<<ch2<<endl;

    return 0;
}