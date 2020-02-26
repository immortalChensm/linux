#include <fcntl.h>
#include <stdio.h>

int main(int argc,char *argv[])
{
	int temp;
	if(argc!=2){
		printf("run error\n");
		return 1;
	}
	printf("pid=%d\n",getpid());
	temp = creat(*(argv+1),S_IRWXU);
	printf("%d\n",temp);

	return 0;
}
