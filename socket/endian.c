#include <stdio.h>
int main(){
    union{
        int n;
        char ch;
    } data;
    data.n = 0x00000001;  //也可以直接写作 data.n = 1;
    //数据是从高到底  1为低字节
    //内存是从低到高
    //
    if(data.ch == 1){
        printf("Little-endian\n");
    }else{
        printf("Big-endian\n");
    }
    return 0;
}
