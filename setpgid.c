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
		printf("the child process PID is %d.\n",getpid());
		printf("the Group ID of child is %d\n",getpgid(0));
		
		sleep(5);//阻塞  时间到了再唤醒
		printf("the Group ID of child is changed to %d\n",getpgid(0));
		exit(0);
	}

	sleep(1);//父进程阻塞，让子进程先运行
	setpgid(pid,pid);//改变子进程的进程组为自己

	sleep(5);//又阻塞，轮到子进程运行  子进程运行后就结束退出

	printf("the parent process PID is %d\n",getpid());
	printf("the parent of parent process PID is %d\n",getppid());
	printf("the Group ID of parent is %d\n",getpgid(0));
	setpgid(getpid(),getppid());//将父进程的进程组ID改为祖先进程
	printf("the Group ID of parent is changed to %d\n",getpgid(0));

	return 0;
}
