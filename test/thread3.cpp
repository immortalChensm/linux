//
// Created by Administrator on 2020/7/9.
//

//
// Created by Administrator on 2020/7/9.
//

#include <iostream>
#include <string>
#include <thread>
#include <string.h>
#include <memory>
#include <vector>
#include <map>
using namespace std;



typedef std::shared_ptr<int> intptr;
class C {
public:
    int _i;
};

typedef std::shared_ptr<C> cptr;

void test(cptr& o)
{

}
int main()
{


    cptr obj = std::make_shared<C>();
    test(obj);

    map<int,int> data;
    for(int i=0;i<10;i++){
        data[i] = i;
    }
//data.erase(5);
    for(auto x:data)
    {

        if(x.first==5){
            data.erase(x.first);
        }
        cout<<x.first<<"="<<x.second<<endl;
    }

    return 0;
}