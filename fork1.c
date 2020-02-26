#include <stdio.h>
#include <stdlib.h>

int main()
{
	int count=0;
	pid_t pid;


	printf("main process id is %d\n",getpid());

	pid = fork();
	if(pid<0){
		printf("error in fork!");
		exit(1);
	}else if(pid==0){
		printf("i am the child process,count is %d,process id is %d\n",count,getpid());
	}else{
		printf("i am the parent process,the count is %d,process id is %d\n",count,getpid());
		printf("运行到这里结束\n");
		exit(0);
	}

	printf("do something\n");
	printf("process %d is over\n",getpid());

	return 0;
}
