#include <stdio.h>
#include <fcntl.h>
#define MAXSIZE 1
#include <errno.h>
#include <stdlib.h>
#include <string.h>
int main(int argc,char *argv[])
{
	int fileId;
	char wbuf[1024]={0};
	int readByte=0;
	fileId = open(argv[1],O_RDONLY);
	printf("fileId=%d\n",fileId);
	if(fileId==-1){
		printf("文件打开错误:%s\n",strerror(errno));
		exit(0);
	}
	while((readByte=read(fileId,wbuf,MAXSIZE))>0){
		printf("%d bytes of %s\n",readByte,wbuf);
	}

	close(fileId);

	return 0;
}
