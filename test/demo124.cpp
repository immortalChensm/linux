//
// Created by Administrator on 2020/6/2.
//

#include <iostream>
#include <string>
//c++流类
//ios / iostream istream ostream ifstream ofstream 流类  标准I/O流  文件I/O流
//cin cout cerr clog 为流对象
//cin<< cout>> 都是调用它的运算符重载函数
using namespace std;

int main()
{
//    int age=0;
//    cin>>age;
//    cout<<age<<endl;
//
//    cerr<<"hello,world"<<endl;
//    clog<<"test"<<endl;

//    std::string url;
//    std::cin>>url;
//    std::cout<<url<<std::endl;
//    std::cerr<<url<<std::endl;
//    std::clog<<url<<std::endl;

    char url[30] = {0};
    cin.getline(url,30);
    //cout.operator<<()
    cout<<cin.gcount()<<endl;
    cout.write(url,30);

    cout.put('a');
    return 0;
}