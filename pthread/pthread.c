#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

pthread_t tid;

void printids(const char *s){
	
	pid_t pid;
	pthread_t tid;

	pid = getpid();
	tid = pthread_self();

	printf("%s pid %u tid %u (0x%x)\n",s,pid,tid,(unsigned int)tid);
}

void *thr_func(void *arg)
{
	printids("new thread:");
	return ((void*)0);
}


void *talk(void *arg)
{
	printf("talking\n");
	return ((void*)0);
}
void *action(void *arg)
{
	printf("action\n");
	return ((void*)0);
}
int main(void)
{
	int err;

	err = pthread_create(&tid,NULL,thr_func,NULL);
	if(err!=0){
		printf("can't create thread:%s\n",strerror(err));
	}
	sleep(1);//主线程阻塞  
	printids("main thread:");
//	sleep(1);//主进程运行后，再阻塞

        
	err = pthread_create(&tid,NULL,talk,NULL);
	sleep(1);
	err = pthread_create(&tid,NULL,action,NULL);
	sleep(1);//主线程阻塞
	printf("run over\n");
	//exit(0);
	return 0;
}
