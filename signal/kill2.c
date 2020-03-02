#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>

int main(void)
{
	pid_t child;
	int status,retval;

	child = fork();

	if(child<0){
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if(child ==0){
		sleep(1000);
		exit(EXIT_SUCCESS);
	}else{
		if((waitpid(child,&status,WNOHANG))==0){

			printf("father process run here\n");
			retval = kill(child,SIGKILL);
			if(retval){
				puts("kill failed\n");
				perror("kill");
				waitpid(child,&status,0);
			}else{
				printf("%d killed\n",child);
			}
		}
	}

	exit(EXIT_SUCCESS);
}
