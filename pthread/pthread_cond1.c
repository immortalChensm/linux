#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t copy = PTHREAD_COND_INITIALIZER;

typedef struct lesson{
	struct lesson *next;
	int hour;
}lesson;

struct lesson *english;

void *student(void *arg)
{
	lesson *eng;
	while(1){
		pthread_mutex_lock(&lock);

		while(english==NULL){
			pthread_cond_wait(&copy,&lock);
		}
		
		eng = english;

		english = eng->next;
		
		printf("stduent listen for %d\n",eng->hour);
		pthread_mutex_unlock(&lock);
		sleep(1);
		
	}	
}

void *teacher(void *arg)
{
	while(1){
		
		lesson *eng = (lesson*)malloc(sizeof(lesson));
		eng->hour = rand()%100+1;
		
		pthread_mutex_lock(&lock);
		eng->next = english;
		english = eng;
		

		printf("teach has spoken %d hour\n",eng->hour);

		pthread_cond_signal(&copy);
		pthread_mutex_unlock(&lock);

		sleep(1);
		
		
	}	
}
int main()
{
	
	pthread_t tid1,tid2;
	
	pthread_create(&tid1,NULL,student,NULL);
	pthread_create(&tid2,NULL,teacher,NULL);

	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);

	return 0;
	
}
