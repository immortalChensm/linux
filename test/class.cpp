//
// Created by Administrator on 2020/6/30.
//

#include <iostream>
#include <string.h>

using namespace std;

template<typename ...args>
class demo {

};

template<typename First,typename ...Others>
class demo<First, Others...>:private demo<Others...>{

public:
    demo():_i(0) {

        cout << "demo class constructor" << endl;
        printf("demo::demo=%p\n",this);
    }

    First _i;
};
struct data{
    int length;
    int age;
};
int main()
{

    int size=0;
    char *recvMessage = (char*)malloc(sizeof(char)*100);

    char *recvBuf = recvMessage+size;
    data d;
    d.age=10;
    d.length = sizeof(d);
    size = sizeof(d);
    memcpy(recvBuf,(char*)&d,size);


    "*****************************";

    recvBuf = recvMessage+size;
    data s;
    s.age=20;
    s.length = sizeof(s);
    size = sizeof(s);
    memcpy(recvBuf,(char*)&s,size);

    data *obj1 = (data*)recvMessage;
    cout<<obj1->age<<endl;

    data *obj2 = (data*)(recvMessage+obj1->length);
    cout<<obj2->age<<endl;

    //demo<int,char,double> obj;
//    data d;
//    d.age=1;
//    d.length = sizeof(d);
//
//    //cout<< sizeof(d)<< sizeof(data);
//    char *dataPool = (char*)malloc(sizeof(char*)*100);
//    //:1|1|1|1....100个
//
//    int size = sizeof(d);
//    memcpy(dataPool,(char*)&d, size);
//
//    data d1;
//    d1.age=2;
//    d1.length = sizeof(d1);
//
//    memcpy(dataPool+ size,(char*)&d1, sizeof(d1));
//    size+=sizeof(d1);
//
//    cout<< sizeof(dataPool)<<endl;
//
//    data *obj1 = (data*)dataPool;
//    cout<<obj1->age<<endl;
//
//    int nSize = size-obj1->length;
//    memcpy(dataPool,dataPool+ sizeof(data), nSize);
//
//
//    data *obj2 = (data*)dataPool;
//    cout<<obj2->age<<endl;
//
//    free(dataPool);
    return 0;
}