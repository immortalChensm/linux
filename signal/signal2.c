#include <stdio.h>
#include <signal.h>
#include <error.h>

static void sigHandler(int);

int main(void)
{
	if(signal(SIGUSR1,sigHandler)==SIG_ERR){
		perror("can't catch SIGUSR1");
	}
	if(signal(SIGUSR2,sigHandler)==SIG_ERR){
		perror("can't catch SIGUSR2");
	}

	printf("pid of this process:%d\n",getpid());

	while(1);
	pause();
}

static void sigHandler(int signo)
{
	if(signo == SIGUSR1){
		printf("received SIGUSR1\n");
	}
	else if(signo == SIGUSR2){
		printf("received SIGUSR2\n");
	}
	else{
		printf("received signal %d\n",signo);
	}
}
