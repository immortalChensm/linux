#include <fcntl.h>
#include <stdio.h>
#include <string.h>
int main(int argc,char *argv[])
{
	int fileId,temp;
	char buf[] = "i like php";
	fileId = open(*(argv+1),O_RDWR|O_CREAT,S_IRWXU);
	printf("%d\n",fileId);
	temp = write(fileId,buf,strlen(buf));
	printf("%d\n",temp);
	close(fileId);
	return 0;
}
