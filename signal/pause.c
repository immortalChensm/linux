#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void handler(int num)
{
	;
}

unsigned int mysleep(unsigned int t)
{
	struct sigaction act,oact;
	act.sa_handler = handler;
	act.sa_flags = 0;

	sigemptyset(&act.sa_mask);
	sigaction(SIGALRM,&act,&oact);

	alarm(t);
	pause();

	int ret = alarm(0);

	sigaction(SIGALRM,&oact,NULL);

	return ret;
}

int main()
{
	while(1){
		printf("hi,i am jack\n");
		mysleep(1);
	}

	return 0;
}
