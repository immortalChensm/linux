#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void print_message(char *ptr);

int main()
{
	pthread_t tid1,tid2;

	char *msg1 = "hello,china";
	char *msg2 = "hello,japanese";

	pthread_create(&tid1,NULL,(void*)(&print_message),(void*)msg1);
	pthread_create(&tid2,NULL,(void*)(&print_message),(void*)msg2);

	sleep(1);

	return 0;
}

void print_message(char *ptr)
{
	int retval;
	printf("thread id:%lx\n",pthread_self());
	printf("%s\n",ptr);
	pthread_exit(&retval);
}
