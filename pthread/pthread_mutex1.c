#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

pthread_mutex_t mutex;
int count=0;
void *eating(void *arg)
{
	int i=0;
	printf("prepare eating\n");
//	pthread_mutex_lock(&mutex);
//	for(i=0;i<count;i++){
//		printf("i am eatting %i\n",i);
//	}
//	pthread_mutex_unlock(&mutex);
//
	while(i<10){
		pthread_mutex_lock(&mutex);
		printf("eating %d\n",i++);
	//	sleep(1);
		pthread_mutex_unlock(&mutex);
	}
	return NULL;

}	

void *watching(void *arg)
{
	int i=0;
	printf("prepare watching\n");
//	pthread_mutex_lock(&mutex);
//	for(i=0;i<count;i++){
//		printf("i am watching tv unitl %d\n",i);
//	}
//	pthread_mutex_unlock(&mutex);
	while(i<10){
		pthread_mutex_lock(&mutex);
		printf("watching %d\n",i++);
	//	sleep(1);
		pthread_mutex_unlock(&mutex);
	}
}

void main(int argc,char *argv[])
{
	pthread_t tid1,tid2;
	pthread_mutex_init(&mutex,NULL);
	count = atoi(argv[1]);

	pthread_create(&tid1,NULL,eating,NULL);
	pthread_create(&tid2,NULL,watching,NULL);

	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);

	printf("main thread run over\n");

	
}
