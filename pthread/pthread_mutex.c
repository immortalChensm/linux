#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define NLOOP 10000

int counter;

pthread_mutex_t counter_mutex = PTHREAD_MUTEX_INITIALIZER;

void *doit(void*);

int main(int argc,char *argv[])
{
	pthread_t tidA,tidB;
	pthread_create(&tidA,NULL,doit,(void*)"thread A");
	pthread_create(&tidB,NULL,doit,(void*)"thread B");

	pthread_join(tidA,NULL);
	pthread_join(tidB,NULL);
	//sleep(2);
	printf("main thread get counter is :%d\n",counter);
	return 0;
}

void *doit(void *vptr)
{
	int i,val;
	for(i=0;i<NLOOP;i++){
		pthread_mutex_lock(&counter_mutex);
		val = counter;
		printf("thread %s %x:%d\n",(char*)vptr,(unsigned int)pthread_self(),val+1);
		counter  = val+1;
		
		pthread_mutex_unlock(&counter_mutex);
	}
	return NULL;
}
