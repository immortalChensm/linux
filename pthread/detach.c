#include <errno.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void *func(void *arg)
{
	int i = *(int*)(arg);
	printf("i am worker:%d\n",i);
}

int main(void)
{
	pthread_t tid;
	int j;

	int count = 100;

	for(j=0;j<count;j++){
		int *p = &(j);
		int ret = pthread_create(&tid,NULL,func,(void*)p);
		
		if(ret){
			printf("create thread error:%d\n",ret);
		}else{
			pthread_detach(tid);
		}
	}

	printf("main thread run over\n");
	printf("process PID:%d\n",getpid());
	return 0;
}
