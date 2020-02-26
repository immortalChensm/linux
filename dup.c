#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc,char *argv[])
{
	int fileId;
	if(argc!=2){
		printf("arg error\n");
		return 1;
	}

	if((fileId=open(argv[1],O_WRONLY|O_CREAT,0644))==-1){
		printf("open %s error\n",argv[1]);
		return 2;
	}

	printf("the old fileId is %d\n",fileId);

	int writeByte = write(fileId,"hello,world\n",12);
	printf("write byte %d\n",writeByte);

	if((fileId=dup(fileId))==-1){
		printf("dup error\n");
		return 3;
	}

	printf("new fileId is %d\n",fileId);
	writeByte = write(fileId,"hello,china\n",12);
	printf("write %d bytes\n",writeByte);

	close(fileId);

	return 0;
}
