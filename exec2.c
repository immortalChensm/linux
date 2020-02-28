#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
	pid_t pid;

	printf("this is a test for exec function\n");

	if(fork()==0){
		execl("/bin/date","/bin/date",(char*)0);
		exit(0);
	}else{
		sleep(2);
	}

	exit(0);
}
