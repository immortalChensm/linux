#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
int main(int argc,char *argv[])
{
	unsigned char temp;
	char npath[200];

	if(argc!=3){
		perror("arg is wrong!\n");
		return 1;
	}

	temp = mkdir(argv[1],S_IRUSR|S_IWUSR|S_IXUSR);
	if(temp==-1){
		printf("create dir failed!\n");
	}

	temp = chdir(argv[1]);
	printf("%d\n",temp);

	if(getcwd(npath,200)==NULL){
		printf("getwd error\n");
	}else{
		printf("cwd=%s\n",npath);
	}

	return 0;
}
