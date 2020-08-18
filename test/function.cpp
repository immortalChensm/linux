//
// Created by Administrator on 2020/7/17.
//

#include <functional>
#include<chrono>
#include <iostream>
using namespace std::chrono;
class CELLTime
{
public:
    static time_t  getNowTimeInMilliSec()
    {
        return  duration_cast<milliseconds>(high_resolution_clock::now().time_since_epoch()).count();
    }
};

int main()
{

//    std::function<void (int)> call;
//    int r=10;
//    call = [r](int a){
//        printf("%d\n",a+r);
//    };
//
//    call(100);
//
//    [r](int a){
//        printf("t=%d\n",a+r);
//    }(100);

//    time_t start = CELLTime::getNowTimeInMilliSec();
//    std::cout<<start<<"\n";
//
//
//    for(int i=0;i<10000000;i++){
//
//        ;
//        std::cout<<CELLTime::getNowTimeInMilliSec()<<"\n";
//    }
//    time_t end = CELLTime::getNowTimeInMilliSec()-start;
//    std::cout<<"end="<<end<<"\n";
    return 0;

}