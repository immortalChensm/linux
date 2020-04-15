//
// Created by Administrator on 2020/4/14.
//

#include <iostream>
#include <string>

using namespace std;

class person
{
public:
    char *name;
    int age;
    int score;
    void display()//类体中的函数默认为内联函数
    {
        cout<<name<<"'s age is "<<age<<",score is "<<score<<endl;
    }
    void talk();//类体中声明
};
void person::talk(){//类体外里定义  不让它是内联函数  内联函数类似宏替换
    cout<<"talk method"<<name<<"'s age is "<<age<<",score is "<<score<<endl;
}
int main()
{



//    person tom;//分配到栈区
//    tom.name = "tom";
//    tom.age = 100;
//    tom.score=100;
//    tom.display();
//
//    person allpeople[2];
//    allpeople[0].name="lucy";
//    allpeople[0].age=100;
//    allpeople[0].score=90;
//
//    allpeople[0].display();


    person *jack = new person;//分配到堆区
    jack->name="jack";
    jack->score=100;
    jack->age=200;
    jack->display();
    jack->talk();



    delete jack;
    return 0;
}