//
// Created by Administrator on 2020/4/13.
//

#include <iostream>
#include <string>

using namespace std;
namespace test
{
    void echo(char *content){
        printf("%s\n",content);
    }

    void echo1(string str){
        cout<<str<<endl;
    }
}
int sum(int n)
{
    int total=0;
    for (int i = 0; i <=n ; ++i) {

        total+=i;
    }
    return total;
}
using namespace test;
int main()
{

    cout<<"input a number:\n";
    int n;
    cin>>n;
    cout<<"result:"<<sum(n)<<endl;

    echo("hello,world");

    echo1("hello,china");
    return 0;
}