//
// Created by Administrator on 2020/5/21.
//

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{

    char *str = (char*)"GET /index.html HTTP/1.1\r\n";
    char *url = strpbrk(str," \t");
    printf("%s\n",url);
    printf("%s\n",str);

    //*url++ ='\0';
    //printf("%s\n",url);
    //printf("%s\n",str);
    if (strcasecmp(str,"GET")==0){
        printf("%s\n","get");
    }else{
        printf("not get\n");
    }

    int i = strspn(url," \t");
    printf("%d\n",i);

    char *version = strpbrk(url," \t");
    printf("%s\n",version);
    printf("%s\n",url);
    return 0;
}