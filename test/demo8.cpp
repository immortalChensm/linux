//
// Created by Administrator on 2020/4/13.
//

#include <iostream>
#include <string>

using namespace std;

int main()
{

    int x,y;
//    bool flag;
//
//    cin>>x>>y;
//
//    flag = x>y;
//    cout<<"flag = "<<flag<<endl;

    int *p = new int[10];
    p[0] = 1;
    p[1] = 2;
    cout<<p[0]<<"\n"<<p[1]<<endl;
    delete [] p;

    return 0;
}