#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void sigHandler(int signo)
{
	printf("%d\n",signo);
}

int main()
{
	signal(SIGABRT,sigHandler);

	printf("do something\n");

	sleep(1);

	abort();

	printf("nothing\n");

	exit(1);
}
