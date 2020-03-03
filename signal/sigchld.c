#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
void handler(int signum)
{
	int status = 0;

	pid_t ret = waitpid(-1,&status,0);
	if(ret>0){
		printf("wait child success!!!sig:%d,exitcode:%d\n",signum,status);
	}else{
		printf("child quit\n");
	}
}

int main()
{
	signal(SIGCHLD,handler);

	pid_t id;
	id = fork();

	if(id==0){
		printf("i am child ,pid:%d,ppid:%d\n",getpid(),getppid());
		sleep(5);
		exit(1);
	}

	while(1){
		printf("i am father,pid:%d,ppid:%d\n",getpid(),getppid());
		sleep(1);
	}

	return 0;
}
