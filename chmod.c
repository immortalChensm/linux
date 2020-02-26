#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
int main(void)
{
	struct stat buf;
	if(stat("foo",&buf)<0){
		printf("stat error\n");
		return 1;
	}

	printf("%d\n",buf.st_size);

	printf("%d\n",buf.st_mode);

	if(chmod("foo",(buf.st_mode&~S_IRUSR))<0){
		printf("chmod error\n");
		return 2;
	}
	return 0;
}
