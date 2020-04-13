//
// Created by Administrator on 2020/4/13.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
class person
{
public:
    int age;
    char *name;
    char *address;
    void show(){
        printf("%s age is %d,address is %s\n",name,age,address);
    }
};
int main()
{
    person tom;
    tom.name = "tom";
    //strcpy(tom.name,"tom");
    tom.age = 100;
    tom.address = "beijing";
    //strcpy(tom.address,"beijing");

    tom.show();
    return 0;
}