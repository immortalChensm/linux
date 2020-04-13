//
// Created by Administrator on 2020/4/13.
//

#include <stdio.h>
#include <stdlib.h>

namespace Test{

    class Person
    {
    private:
        int age=100;
        char *name="lucy";
    public:
        void display()
        {
            printf("%s is %d\n",name,age);
        }
    };
};

int main()
{
    Test::Person people;
    people.display();

    return 0;
}