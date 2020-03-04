#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc,char *argv[])
{
	int fd;
	int ret;

	ret = mkfifo("my_fifo",0666);
	if(ret!=0){
		perror("mkfifo error");
	}

	fd = open("my_fifo",O_WRONLY);
	if(fd<0){
		perror("open fifo error");
	}

	char send[100] = "hello world";
	write(fd,send,strlen(send));

	printf("write to my_fifo buf=%s\n",send);
	while(1);
	close(fd);
	return 0;
}
