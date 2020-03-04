#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	char file[] = "fifo_test";

	if(access(file,F_OK)){
		if(mkfifo(file,0666)){
			perror("mkfifo create error");
		}
	}

	int fd = open(file,O_RDONLY);
	char recv[1024] = {0};
	int len=0;
	if(fd>0){
		
		while(1){
			len = read(fd,recv,sizeof(recv));
			if(len){
				printf("收到客户端的数据：%s\n",recv);
			}else{
				printf("如果不打印此数据则说明命名管道文件读取没有数据则会阻塞");
			}

			memset(recv,0,sizeof(recv));
		}
	}

	close(fd);

	return 0;
}
