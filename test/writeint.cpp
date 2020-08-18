//
// Created by Administrator on 2020/7/29.
//

#include <iostream>
#include <string>
#include <share.h>
#include <memory>
#include <string.h>
#include <vector>

using namespace std;

class A{
public:
    int _i;
    char *_name;
    void show()
    {
        cout<<_i<<_name<<endl;
    }
    void set(int i,char *n){
        _i=i;
        _name = n;
    }
};

class B{
public:
    int _i;

    void show()
    {
        cout<<_i<<endl;
    }
    void set(int i){
        _i=i;

    }
};

void display(char *data)
{
    A *a = (A*)data;
    a->show();
}

template<typename T>
void showData(char *data)
{
    T a;
    memcpy(&a,data, sizeof(T));
    a.show();
}
class C{
public:
    int _dataLen;
    int _cmd;
    void display()
    {

    }
};
class D{
public:
    D()
    {
        _name = new char[100];
    }
    ~D()
    {
        if(_name){
            delete [] _name;
            _name = nullptr;
            cout<<"run here"<<endl;
        }
    }
    void show()
    {
        cout<<"show"<<endl;
    }
public:
    char *_name;
};
int main()
{

//    vector<std::shared_ptr<D>> l;
//    std::shared_ptr<D> o(new D());
//
//
//    l.push_back(o);
//
//
//    vector<std::shared_ptr<D>>::iterator iter= l.begin();
//    (*iter)->show();
//
//    l.erase(iter);


    //cout<<sizeof(float)<<endl;
    //cout<<sizeof(double)<<endl;
    char a=10;//0000 1010 0xa  0000 1010
    //                         0011 0000
    //                         0001 0000


    printf("%#x\n",a);
    printf("%#o\n",a);

    printf("%#x\n",a<<1);
    printf("%#x\n",a);
    printf("%#x\n",a&0b00110000);
    printf("%#x\n",a|0b00110000);
    /**
     * 0000 1010
     * 0011 0000
     * 0011 1010
     * 3a
     * **/

    cout<<"**************"<<endl;

    int b = 9;//00000000 00000000 00000000 00001001
    printf("%#x\n",b);
    printf("%#x\n",0b00000001000000010000000100001001);

    unsigned char c = 255;

    printf("%#x\n",c);//1111 1111
    printf("%#x\n",c>>4);//1111 1111
                          //1111 0000
                            //0000 1111
    printf("%#x\n",0b00001111);

    //$pack   = pack('NN', ($length & 0xFFFFFFFF00000000) >> 32, $length & 0x00000000FFFFFFFF);

    printf("%#lx\n",0xffffffff00000000>>32);
    printf("%#lx\n",0x00000000ffffffff&0b1010);

    char len = 8;//0000 1000

    printf("%#x\n",len&0xffffffff00000000);
    printf("%#x\n",0x08ffffff00000000>>32);


    //printf("%#x\n",65535);
//    char *data = new char[1000];
//
//    int i=0;
//    int cmd=2;
//
//    memcpy(data,&i, sizeof(int));
//    int currentPos= sizeof(int);
//
//    memcpy(data+currentPos,&cmd, sizeof(int));
//    currentPos+= sizeof(int);
//
//    char *name=(char*)"lucy";
//
//    memcpy(data+currentPos,name, sizeof(char)*strlen(name));
//
//    currentPos+=sizeof(char)*strlen(name);
//
//    C *c = (C*)data;
//
//    cout<<"c size="<< sizeof(C)<<",data size="<<currentPos<<endl;
//    cout<<c->_dataLen<<endl;
//    cout<<c->_cmd<<endl;

//    A *a = new A();
//    a->_i=100;
//    a->_name = (char*)"jack";
//
//    memcpy(data,a, sizeof(A));
//    int currentPos = sizeof(A);
//
//    B *b = new B();
//    b->_i=666;
//
//    memcpy(data+currentPos,b, sizeof(B));
//
//    showData<A>(data);
//    showData<B>(data+currentPos);
//
//    currentPos+= sizeof(B);
//
//    char *str=(char*)"i like php\n";
//
//    memcpy(data+currentPos,str, sizeof(char)*strlen(str));
//
//    char *strv=new char[strlen(data+currentPos)];
//
//    memcpy(strv,data+currentPos,strlen(data+currentPos));
//    cout<<strv<<endl;
    //cout<<(data+currentPos)<<strlen(data+currentPos)<<endl;
//    cout<< sizeof(A)<<endl;
//    cout<< sizeof(B)<<endl;
//
//    A *a = (A*)data;
//    a->_i=10;
//    a->_name = (char*)"lucy";
//
//    a->show();
//
//    int currentSize = sizeof(A);
//
//    B *b = (B*)(data+currentSize);
//    b->_i=888;
//
//    b->show();
//
//    cout<<"******************"<<endl;
//
//    display(data);
//    display(data+currentSize);

    //&a 的内存  sizeof(int) a内存的大小
//    memcpy(data,&a,sizeof(int));
//    wLen+=sizeof(int);
//
//    int av=0;
//    memcpy(&av,data,sizeof(int));
//    cout<<av<<endl;

//内存写入和读取的原理：通过控制内存位置
//    int b[3] = {1,2,3};
//
//    int bLen=3;
//    memcpy(data,&bLen,sizeof(int));
//    memcpy(data+sizeof(int),b,sizeof(int)*3);
//
//    int bv[100]={};
//    int bvLen=0;
//    memcpy(&bvLen,data,sizeof(int));
//    memcpy(bv,data+sizeof(int),sizeof(int)*bvLen);
//
//    for(int i=0;i<bvLen;i++){
//        cout<<bv[i]<<endl;
//    }
//
//    cout<<"bvLen="<<bvLen<<endl;

    /** 内存池实现原理****/
//    char *data = new char[1000];
//    int useSize=0;
//    int *a=(int*)data;
//    *a=54321;
//    useSize+=sizeof(int);
//    float *b=(float*)(data+useSize);
//    *b=12345.00f;
//    useSize+=sizeof(float);
//    printf("%f\n",*b);
//    printf("%d\n",*a);
//
//    char *str = (data+useSize);
//    strcpy(str,"hello");
//    printf("%s\n",str);
//

//
//    cout<<"********************"<<endl;
//    printf("%d\n",*(int*)data);
//
//
//    printf("%f\n",*(float*)(data+ sizeof(int)));
//    printf("%s\n",(data+ useSize));
/** 内存池实现原理****/


//    int writeLen=0;
//
//
//    int a=12;int aSize=sizeof(int);
//    memcpy(data+writeLen,(const char*)&a, aSize);
//    writeLen+=aSize;
//    printf("%d\n",*data);
//
//
//    int b=25;int bSize=sizeof(int);
//    memcpy(data+writeLen,&b, bSize);
//
//    printf("%d,%d\n",writeLen,*(data+writeLen));
//
//    writeLen+=bSize;
//
//    char c='a';int cSize=sizeof(char);
//    memcpy(data+writeLen,&c, cSize);
//
//    printf("%c\n",*(data+writeLen));
//
//    writeLen+=cSize;

   // const char *name="jack";int nameSize=sizeof(char)*strlen(name);
    //memcpy(data+writeLen,name, nameSize);
    //writeLen+=nameSize;




    return 0;
}