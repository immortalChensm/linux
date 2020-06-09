//
// Created by Administrator on 2020/6/8.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>

using namespace std;

int main()
{
    char str1[] = "www.baidu.com";

    char *p = find(str1,str1+strlen(str1),'a');
    if(p!=str1+strlen(str1)){
        cout<<p<<endl;
    }

    vector<int> myvector{1,2,3,4,5};
    vector<int>::iterator it;

    it = find(myvector.begin(),myvector.end(),3);
    if(it!=myvector.end()){
        cout<<*it<<endl;
    }else{
        cout<<"find error"<<endl;
    }
    return 0;
}