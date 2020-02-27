#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <fcntl.h>
//守护进程
int main()
{
	pid_t pid;
	int i,fd;

	if((pid=fork())<0){
		printf("fork error.\n");
		exit(1);
	}else if(pid>0){
		exit(0);
	}

	setsid();

	chdir("/");

	umask(0);

//	for(i=0;i<getdtablesize();i++){
	//	close(i);
		//printf("%d\n",i);
//	}

	while(1){
		sleep(1);
		printf("process PID %d do something!\n",getpid());
		printf("process Group Id %d\n",getpgrp());
		printf("session ID %d\n",getsid());
	}

	return 0;
}
