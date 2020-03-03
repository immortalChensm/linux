#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

void inthandler(int signum);
void continuehandler(int signum);
void terminatehandler(int signum);

int main(void)
{
	char buffer[100];

	signal(SIGINT,&inthandler);
	signal(SIGTSTP,&inthandler);
	signal(SIGCONT,continuehandler);
	signal(SIGTERM,terminatehandler);

	printf("pid of this process:%d\n",getpid());

	while(1){
		printf("please input:\n");
		fgets(buffer,sizeof(buffer),stdin);
		
		if(strcmp(buffer,"int")==0){
			raise(SIGINT);
		}
		else if(strcmp(buffer,"stop")==0){
			raise(SIGTSTP);
		}

		else if(strcmp(buffer,"continue")==0){
			raise(SIGCONT);
		}
		else if(strcmp(buffer,"quit")==0){
			raise(SIGTERM);
		}
		else{
			printf("your input is:%s\n",buffer);
		}
	}

	exit(0);
}

void inthandler(int signum)
{
	printf("catch signal %d\n",signum);
}

void continuehandler(int signum)
{

	printf("continue code.\n");

}

void terminatehandler(int signum)
{
	printf("signal SIGTERM\n");
	exit(0);
}
