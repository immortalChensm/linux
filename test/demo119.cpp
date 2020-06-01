//
// Created by Administrator on 2020/6/1.
//

#include <iostream>
#include <string.h>
//数据类型转换
using namespace std;

namespace test
{
    int age=100;
}

int main()
{
    cout<<test::age<<endl;

    using namespace test;
    cout<<age<<endl;

    float t = (float)age;
    cout<<t<<endl;
    printf("%lf\n",t);

    float j = static_cast<float>(age);
    char a = const_cast<char>(age);
    cout<<a<<endl;
    cout<<j<<endl;
    return 0;
}