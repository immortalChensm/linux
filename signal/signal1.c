#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void signalDeal(int sigNum)
{
	printf("the signal no is :%d\n",sigNum);
	return ;
}

int main(void)
{
	signal(SIGINT,signalDeal);

	while(1){
		printf("%d i am running\n",getpid());
		sleep(1);
	}

	return 0;
}
