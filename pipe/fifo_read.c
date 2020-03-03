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

	fd = open("my_fifo",O_RDONLY);

	if(fd<0){
		perror("open fifo error");
	}

	while(1){
		char recv[100] = {0};

		read(fd,recv,sizeof(recv));

		printf("read from my_fifo buf=[%s]\n",recv);
		sleep(1);
	}

	close(fd);

	return 0;
}
