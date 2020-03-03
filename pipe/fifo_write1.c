#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
int main()
{
	char *mkfile = "fifo_test";
	int fd;
	if(access(mkfile,F_OK)){
	//	printf("fifo_test file not exist\n");
	//	return 0;
	//
		if(mkfifo(mkfile,0666)){
			printf("mkfifo create error\n");	
			return 1;
		}
	}

	fd = open(mkfile,O_WRONLY);
	if(fd<0){
		perror("open file error\n");
	}
	char send[1024] = {0};
	while(1){
		
		fgets(send,sizeof(send),stdin);
		if(strlen(send)){
			write(fd,send,strlen(send));
		}
	}
	return 0;
}
