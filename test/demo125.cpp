//
// Created by Administrator on 2020/6/3.
//

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str = "www.baidu.com";
    for (int i = 0; i <str.length() ; ++i) {

        cout.put(str[i]);
    }
    cout.put('\n');

    putchar('b');
    string temp = (char*)"***********************************";
    cout.write("abc",3);

    cout.write(temp.c_str(),temp.length());

    return 0;
}