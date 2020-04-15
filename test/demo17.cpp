//
// Created by Administrator on 2020/4/15.
//

#include <iostream>
#include <string>
using namespace std;
//c++函数的编译原理和类成员函数的实现原理
//c++会把所有的函数和类的成员函数经过Name Mangling算法重命名为全局函数
//而类的成员函数调用的对象成员属性是将当前实例的内存【指针】传递给成员函数的


//c++在编译函数时会进行函数重命名操作 Name Mangling算法
//全局函数重载声明
void display();
void display(char );
//命名空间里的函数声明
namespace jack{
  void display(int);
};
//类体里的内联函数声明
class Lucy
{
private:
    int age;
    char name;
public:
    void display(float);//成员函数最终会编译成全局函数  与对象无关  而它调用的类的成员变量 只是把当前对象的指针【内存】传递给此函数，以便此函数通过内存【指针】访问成员

    void talk();
};
//此函数会被编译【经过算法】成全局函数，同时访问的类成员变量就是如下
//_new_function_name(&obj);
/**
 * 当Lucy obj;
 * obj.talk()时编译如下：
 * void _new_talk(Lucy const *obj)
 * {
 *      cout<<obj->name<<obj->age<<endl;
 * }
 *
 * 当Lucy obj1 = new Lucy;
 * obj1->display();时编译为 _new_display(&obj1);
 */
void Lucy::talk() {
    cout<<name<<age<<endl;
}
int main()
{

    display();
    display('a');
    jack::display(100);
    Lucy lucy;
    lucy.display(12.45f);

    return 0;
}