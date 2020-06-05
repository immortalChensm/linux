//
// Created by Administrator on 2020/6/5.
//

#include <iostream>
#include <string.h>

using namespace std;

namespace jack
{
    class demo
    {
    public:
        static int type;
    public:
        void width(int w);
        void height(int h);
        ostream & operator<<(int &ret);
    private:
        int m_width;
        int m_height;
    };
    int demo::type = 0;
    void demo::height(int h) {
        this->m_height = h;
    }
    void demo::width(int w) {
        this->m_width=w;
    }
    ostream &  demo::operator<<(int &ret) {
        if (type==1){
            ret = this->m_width*this->m_height;
            cout<<"ret="<<ret;
        }else{
            ret = this->m_width+this->m_height;
            cout<<"ret:"<<ret;
        }

        return cout;

    }

    demo tom;
}

int main()
{

//    double a = 1.23;
//    cout.precision(4);
//    cout<<"precision:"<<a<<endl;
//
//    cout.setf(ios::scientific);
//    cout<<"scientific:"<<a<<endl;
//
//    cout<<"***********************"<<endl;
//
//    using namespace jack;
//    tom.width(100);
//    tom.height(180);
//    demo::type=2;
//    int ret;
//    tom<<ret<<endl;
//
//    cout<<ret<<endl;

    cout<<"---------------------"<<endl;

    double f = 123;
    cout.setf(ios::scientific);
    cout<<f<<"\n";
    cout.unsetf(ios::floatfield);
    cout<<f;

    return 0;

}