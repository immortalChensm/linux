#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main(void)
{
	pid_t pid;
	int status;
	pid = fork();
	if(pid<0){
		exit(0);
	}else if(pid==0){

		printf("我是子进程%d，父进程是:%d,我属于%d进程组\n",getpid(),getppid(),getpgid(getpid()));
		printf("我没事了，准备退出结束，父进程销毁\n");
		exit(0);
	}else{
		
		pid = wait(&status);
		printf("父进程在等子进程\n");
		printf("结束的子进程:%d\n",pid);

		printf("父进程所属的进程组ID：%d\n",getpgrp());

		
	}

	printf("%d run over\n",getpid());
	return 0;
}
