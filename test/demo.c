//
// Created by 1655664358@qq.com on 2020/3/23.
//

#include <stdio.h>
#include <stdlib.h>

#define XXX int
struct test{
    unsigned char c;
};

//struct test a = {
//        .c = 5
//};

struct test a = {
    c:3
};

union testc{
    int data;
    char age;
};

#define BBC struct {int height;char message[100];}

struct {
    int age;
    char name[10];
    struct {
        int address;
    };

    union {
        char gender;
        int sex;
    };

    BBC test;
} lucy = {.age=100,.name="lucy",.address=1000,.gender='F',.sex=300,.test.message="hello",.test.height=190};

struct tony
{
    int age;
};
int main()
{
    ;

//    struct tony tony1 = {.age=100};
//
//    struct tony *tony2 = &tony1;
//
//    tony2->age = 10;
//
//    printf("%d,%d\n",tony1.age,tony2->age);
    printf("%d\n",1u<<1);
    //10000000
    //00010000
    //10010000
    //90

    //printf("%#X\n",0x80|0x10);
    //printf("%s=%d,gender=%c,sex=%d\n",lucy.name,lucy.address,lucy.gender,lucy.sex);

    //printf("%s is %d\n",lucy.test.message,lucy.test.height);
//    //a.c=2;
//    XXX age=100;
//    printf("%d\n",a.c);
//    printf("%d\n",age);
//    union testc tony;
//    tony.data=100;
//    tony.age=10;
//    printf("%d\n",tony.data);
//    tony.data=100;
//    printf("%d\n",tony.data);
//    printf("%d\n", sizeof(tony));
//    printf("%d\n", sizeof(tony.data));
//    printf("%d\n", sizeof(tony.age));
//    printf("%d\n", sizeof(union testc));
    return 0;
}

