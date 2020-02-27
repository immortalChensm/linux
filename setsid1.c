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
		printf("the child process PID is %d\n",getpid());
		printf("the Group ID of child is %d\n",getpgid(0));
		printf("the Session ID of child is %d\n",getsid(0));

		sleep(10);
		setsid();

		printf("changed:\n");
		printf("the child process PID is %d\n",getpid());
		printf("the Group ID of child is %d\n",getpgid(0));
		printf("the Session ID of child is %d\n",getsid(0));

		sleep(20);
		exit(0);
	}

	return 0;
}
