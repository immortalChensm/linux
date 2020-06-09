//
// Created by Administrator on 2020/6/8.
//

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> obj;

    for(int i=0;i<10;i++){
        obj.push_back(i);
        cout<<obj[i]<<",";
    }

    for(int i=0;i<5;i++){
        obj.pop_back();
    }

    cout<<"\n";

    for (int j = 0; j <obj.size() ; ++j) {

        cout<<obj[j]<<",";
    }

    return 0;
}