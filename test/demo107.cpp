//
// Created by Administrator on 2020/5/22.
//

#include <iostream>
#include <string>

using namespace std;

void func(string str)
{
    cout<<"**************"<<endl;
    cout<<str<<endl;
    cout<<"**************"<<endl;
}

int main()
{
    string s1 = "http://www.baidu.com";
    string s2(s1);
    string s3 = s1;
    string s4 = s1+""+s2;
    func(s1);

    cout<<s1<<endl<<s2<<endl<<s3<<endl<<s4<<endl;

    string s5("china is developed country!");
    cout<<s5<<endl;

    return 0;
}