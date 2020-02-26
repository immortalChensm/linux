#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("hello,world\n");

    char a[] = "hello";
    printf("%c\n",a[0]);
    printf("%c\n",*a);
    printf("%c\n",*(a+1));

    printf("%c\n",*&*(a+1));

    char *b[] = {"hello","world","china"};
    /**
     * 变量名 b
     * 变量类型 char
     * 变量内容
     * 变量地址
     *
     * 变量只是地址的助记符号  本身就是内存地址
     * 指针变量：只是存储内存地址的变量
     *
     * 数组：是连续的内存存储空间 内存地址是连续的
     * 数组名=数组的首个元素地址
     * b=&b[0]
     * b[0]=&b[0][0]
     */
    printf("%s\n",b[0]);
    printf("%#X\n",b);
    printf("%#X\n",&b[0]);
    printf("%#X\n",b[0]);
    printf("%#X\n",&b[0][0]);
    printf("%#X\n",&b[0][1]);
    printf("%#X\n",&b[0][2]);

    printf("%s\n",*b);
    printf("%s\n",*(b+1));
    return 0;
}