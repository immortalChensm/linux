//
// Created by Administrator on 2020/6/4.
//

#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
using namespace std;

int main()
{
    std::ofstream outfile;

    outfile.open("test.txt");

    const char *str = "http://www.baidu.com";

    for (int i = 0; i <strlen(str) ; ++i) {

        outfile.put(str[i]);

        long pos = outfile.tellp();

        std::cout<<pos<<std::endl;
    }

    outfile.close();
    return 0;
}