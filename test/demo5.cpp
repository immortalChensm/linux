//
// Created by Administrator on 2020/4/13.
//

#include <iostream>
#include <string>


void display()
{
    std::cout<<"hello,world"<<std::endl;
}
int main()
{
    using namespace std;

    string str;

    int age;

    cin>>str>>age;

    cout<<str<<age<<endl;


    printf("***************\n");
    display();
    return 0;
}