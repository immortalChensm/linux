#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/types.h>
void talk(sem_t *sem,char *msg)
{

	int i=0;
	while(1){
		
		sem_wait(sem);
		printf("process pid=%d run %d of %s\n",getpid(),i++,msg);

		sem_post(sem);

		sleep(1);
	}
}
int main()
{
	
	printf("main procss pid=%d\n",getpid());
	sem_t *sem = NULL;
	pid_t pid = fork();

	printf("fork pid=%d\n",pid);

	if(pid==0){
		
		sem = sem_open("sem_open3",O_RDWR|O_CREAT,0666,1);
		if(sem== SEM_FAILED){
			perror("sem_open3 error");
			return -1;
		}

		talk(sem,"child process");
		
		sem_close(sem);

		exit(0);

	}
	else{
	
		pid = fork();

		setpgid(pid,getpid());	

		if(pid==0){
			
			sem = sem_open("sem_open3",O_RDWR|O_CREAT,0666,1);			
			if(sem == SEM_FAILED){
				exit(0);
			}

			talk(sem,"laobiao");

			sem_close(sem);

			exit(0);
		}

		sem = sem_open("sem_open3",O_CREAT|O_RDWR,0666,1);
		if(sem == SEM_FAILED){
			perror("sem_open3 error");
			return -1;
		}

		talk(sem,"fathre process");

		sem_close(sem);

		wait(pid,NULL);
	}

	sem_unlink("sem_open3");

	printf("process pid=%d is over\n",getpid());

	
	return 0;
}
