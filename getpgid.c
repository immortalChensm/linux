#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	pid_t pid;

	if((pid=fork())<0){
		printf("fork error\n");
		exit(0);
	}
	else if(pid==0){
		printf("the child process PID is %d\n",getpid());
		printf("the Group ID is %d\n",getpgrp());
		printf("the Group ID is %d\n",getpgid(0));
		printf("the Group ID is %d\n",getpgid(getpid()));
	}

	sleep(3);
	printf("the parent process PID is %d\n",getpid());
	printf("the Group ID is %d\n",getpgrp());

	return 0;
}
