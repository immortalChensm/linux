//
// Created by Administrator on 2020/4/15.
//

#include <iostream>
#include <string>
//对象数组
using namespace std;

class Demo
{
public:
    Demo(){
        cout<<"constructor 1 called\n";
    }
    Demo(int a){
        cout<<"constructor 2 called\n";
    }
};

int main()
{
//    Demo objarr[2];
//
//    cout<<"************************\n";
//    Demo objarr1[2] = {2,3};
//    cout<<"*************************\n";
//    Demo objarr2[2] = {3};
//    cout<<"**************************\n";
//    Demo *objarr3 = new Demo[2];
//    delete [] objarr3;
//    cout<<"**************************\n";
//    Demo *objarr5 = new Demo[3];
//    delete [] objarr5;

    cout<<"----------------------"<<endl;

    Demo *arr[2] = {new Demo(100),new Demo(200)};

    delete [] arr[0];
    delete [] arr[1];


    int *arr1[2] = {new int ,new int};
    arr1[0]=(int*)100;
    arr1[2]=(int*)200;


    return 0;
}