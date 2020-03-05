#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <fcntl.h>
#include <unistd.h>

sem_t *sem1,*sem2;

void speaking(char *str)
{
	int i=10;
	while(i--){

		sem_wait(sem1);
		printf("pid %d speaking with %s\n",getpid(),str);
		sleep(1);

		sem_post(sem2);
	}
	
}

void copying(char *str)
{
	int j=10;
	while(j--){
		sem_wait(sem2);
		printf("pid %d\n copyring %s\n",getpid(),str);
		sleep(1);

		sem_post(sem1);
	}
}
int main()
{
	//sem_t *sem1,*sem2;

	//有名信号 实现进程间同步
	//互斥：是指各进程间互相使用一个信号量
	//同步：是指各进程间拥有自己的信号量
	pid_t pid;

	pid = fork();

	if(pid<0){
		perror("fork error");
		exit(0);
	}
	else if(pid == 0){

		sem1 = sem_open("sem1",O_CREAT,0777,1);
		if(SEM_FAILED == sem1){
			perror("sem1 open error");
			return 0;
		}
		speaking("child");
		sem_close(sem1);
		_exit(0);
	}else if(pid>0){
		
		sem2 = sem_open("sem2",O_CREAT,0777,0);
		if(sem2 == SEM_FAILED){
			perror("sem2 open error");
			exit(0);
		}
		copying("father");
		sem_close(sem2);

		wait(pid,NULL);//阻塞等子进程结束
		
	}

	sem_unlink("sem1");
	sem_unlink("sem2");

	return 0;
}
