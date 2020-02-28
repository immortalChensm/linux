#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	pid_t pid;

	if((pid=fork())<0){
		printf("fork error.\n");
		exit(1);
	}

	else if(pid==0){
		
		printf("child process PID is %d\n",getpid());
		printf("child Group ID is %d\n",getpgid(0));
		printf("child Group Id is %d\n",getpgrp());
		exit(0);
	}

	sleep(3);

	printf("parent process PID is %d\n",getpid());
	printf("parent process of parent PID is %d\n",getppid());
	printf("paent Group Id is %d\n",getpgrp());

	return 0;
}
