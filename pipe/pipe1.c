#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
	int fd[2];

	pid_t pid;

	char str[1024] = "hello\n";
	char buf[1024];

	//创建匿名管道 返回读写2个文件描述符 
	if(pipe(fd)<0){
		perror("pipe");
		exit(1);
	}

	pid = fork();

	if(pid>0){
		close(fd[0]);//关闭读端
		sleep(2);//阻塞 2秒
		printf("fathre process PID:%d write data\n",getpid());
		write(fd[1],str,strlen(str));
		wait(NULL);//写入数据后  阻塞当前进程  同时等待子进程的执行并回收
	}
	else if(pid==0){
		close(fd[1]);//关闭写端
		int len = read(fd[0],buf,sizeof(buf));//从读端读取数据  如果写端没有关闭  没有数据时则会阻塞当前进程  则父进程过2秒后会写入数据
		write(STDOUT_FILENO,buf,len);//子进程输出读取的数据
		printf("child process %d\n",getpid());
	}
	else{
		perror("fork");
		exit(1);
	}

	printf("process PID:%d run over\n",getpid());
	return 0;
}
