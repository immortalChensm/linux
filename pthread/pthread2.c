#include <stdio.h>
#include <stdlib.h>

#include <pthread.h>

void print_message(char *args);
int main()
{
	pthread_t tid1,tid2;
	char *msg1 = "hello";
	char *msg2 = "world";
	void *retval;
	pthread_create(&tid1,NULL,(void*)(&print_message),(void*)msg1);
	pthread_create(&tid2,NULL,(void*)(&print_message),(void*)msg2);
	
	pthread_join(tid1,&retval);
	pthread_join(tid2,&retval);
	
	printf("thread %d exit status %d\n",tid1,*(int*)retval);
	return 0;
}

void print_message(char *args)
{
	printf("%d-%ld-%s\n",getpid(),pthread_self(),args);
	int i;
	for(i=0;i<10;i++){
		printf("%d-%s\n",i,args);
	}
	int retval=100;
	pthread_exit(&retval);
}
