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
//    char str1[] = "www.baidu.com";
//
//    char *p = find(str1,str1+strlen(str1),'a');
//    if(p!=str1+strlen(str1)){
//        cout<<p<<endl;
//    }
//
//    vector<int> myvector{1,2,3,4,5};
//    vector<int>::iterator it;
//
//    it = find(myvector.begin(),myvector.end(),3);
//    if(it!=myvector.end()){
//        cout<<*it<<endl;
//    }else{
//        cout<<"find error"<<endl;
//    }

    vector<int> age{100,200,300,400,500};

    for (int i = 0; i <age.size() ; ++i) {

        cout<<age[i]<<endl;

        if (age[i]==300){

           auto it = age.begin();
           if (it!=age.end()){
               age.erase(it);
           }

        }
    }
cout<<"**********************"<<endl;

    age.erase(age.end());
    for (int i = 0; i <age.size() ; ++i) {

        cout<<age[i]<<endl;

    }
    return 0;
}