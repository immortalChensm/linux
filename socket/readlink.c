#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main()
{
	char *file = "demo1.php";

        if(!access(file,F_OK)){
		char buf[1024];
		int ret = readlink(file,buf,sizeof(buf));

		printf("ret=%d,buf=%s\n",ret,buf);
	}	

	return 0;
}
