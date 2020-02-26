#include <stdio.h>
#include <fcntl.h>

int main(int argc,char *argv[])
{
	int temp,seektemp,i,j;
	int fileId;

	char buf[]="this is a test!\r\n";
	if(argc!=2){
		printf("run error!\n");
		return 1;
	}

	fileId = open(*(argv+1),O_RDWR|O_CREAT,S_IRWXU);
	temp = write(fileId,buf,sizeof(buf));
	seektemp = lseek(fileId,0,SEEK_CUR);
	printf("当前文件的偏移量：%d\n",seektemp);

	for(i=0;i<10;i++){
		j = sizeof(buf)*(i+1);
		seektemp = lseek(fileId,j,SEEK_SET);
		temp = write(fileId,buf,sizeof(buf));
	}
	close(fileId);
	return 0;
}
