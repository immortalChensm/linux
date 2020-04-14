//
// Created by Administrator on 2020/4/14.
//

#include <iostream>
#include <string>

using namespace std;

//#define SQ(y) y*y
#define SQ(y) (y)*(y)
inline SQ1(int y){return y*y;}//仅用于代替带参数宏替换
int main()
{

    int n,sq;
    cin>>n;
    //sq = SQ(n+1);//9+1*9+1
    sq = SQ1(n+1);
    cout<<sq<<endl;

    return 0;
}