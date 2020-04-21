//
// Created by Administrator on 2020/4/21.
//

#include <stdlib.h>
#include <stdio.h>

int swap1(int *p1,int *p2);
int main()
{
    int num1,num2;
    /**
     * num1 0x1=10
     * num2 0x2=20
     */
    scanf("%d",&num1);
    scanf("%d",&num2);

    printf("%d=%d\n",num1,num2);
    printf("%#x,%#x\n",&num1,&num2);
    swap1(&num1,&num2);
    printf("%d=%d\n",num1,num2);

    return 0;
}

//p1 0x3=0x1
//p2 0x4=0x2
int swap1(int *p1,int *p2)
{
    //printf("%#x,%#x\n",p1,p2);
    //temp 0x5=0x1
    int *temp = p1;//
    //0x3=0x2
    p1=p2;
    //0x4=0x1
    p2=temp;
    //printf("%#x,%#x\n",p1,p2);
    //*0x2 *0x5
    //printf("%d=%d\n",*p1,*p2);
    return 0;
}