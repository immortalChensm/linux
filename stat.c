#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
int main(int argc,char *argv[])
{
	int i;
	struct stat buf;
	char *ptr=NULL;

	if(stat(argv[1],&buf)<0){
		printf("stat error");
		exit(0);
	}

	if(S_ISREG(buf.st_mode)){
		ptr = "regular";
	}
	else if(S_ISDIR(buf.st_mode)){
		ptr="directory";
	}
	else if(S_ISCHR(buf.st_mode)){
		ptr="character special";
	}
	else if(S_ISFIFO(buf.st_mode)){
		ptr="fifo";
	}
	else if(S_ISLNK(buf.st_mode)){
		ptr="symbolic link";
	}
	else if(S_ISSOCK(buf.st_mode)){
		ptr="sock file";
	}else{
		ptr="unknow mode";
	}
	printf("%s--%d\n",ptr,buf.st_size);
	return 0;
}
