#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define SIZE 0x100000

void *th_fun(void *arg)
{
	while(1){
		sleep(1);
		printf("thread %d run \n",pthread_self());
	}
	
}

int main(void)
{
	pthread_t tid;
	int err,detachstate,i=1;
	pthread_attr_t attr;
	size_t stacksize;
	void *stackaddr;

	pthread_attr_init(&attr);
	pthread_attr_getstack(&attr,&stackaddr,&stacksize);
	printf("栈地址:%#x,栈大小:%d\n",stackaddr,stacksize);

	//获取线程分离状态
	pthread_attr_getdetachstate(&attr,&detachstate);
	
	if(detachstate == PTHREAD_CREATE_DETACHED){
		printf("thread detached\n");
	}
	else if(detachstate == PTHREAD_CREATE_JOINABLE){
		printf("thread join\n");
	}else{
		printf("thread unknow\n");
	}

	pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);

	while(i<=10){
		stackaddr = malloc(SIZE);
		if (stackaddr == NULL){
			perror("malloc");
			exit(1);
		}

		stacksize = SIZE;
		pthread_attr_setstack(&attr,stackaddr,stacksize);
		err = pthread_create(&tid,&attr,th_fun,NULL);
		if(err!=0){
			printf("%s\n",strerror(err));
			exit(1);
		}
		printf("%d\n",i++);
	}
	sleep(12);
	printf("main run over\n");
	pthread_attr_destroy(&attr);
	return 0;
}
