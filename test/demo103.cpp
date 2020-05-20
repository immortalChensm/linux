//
// Created by Administrator on 2020/5/20.
//

#include <iostream>
#include <string>

using namespace std;

class Base{};
class Derived:public Base{};

int main()
{
    try
    {
        //throw 123;
        throw Base();
        cout<<"hello"<<endl;
    }catch(int e){
        cout<<e<<endl;
    }catch(char * e){
        cout<<e<<endl;
    }catch (Base){
        cout<<"base"<<endl;
    }catch(Derived){
        cout<<"derived"<<endl;
    }

    return 0;
}