#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *func1(void *arg)
{
	printf("thread 1 returnning\n");
	return ((void*)1);
}

void *func2(void *arg)
{
	printf("thread 2 exiting\n");
	pthread_exit((void*)2);
}

int main(void)
{
	int err;
	pthread_t tid1,tid2;
	void *ret;

	err = pthread_create(&tid1,NULL,func1,NULL);
	err = pthread_create(&tid2,NULL,func2,NULL);

	pthread_join(tid1,&ret);//主进程阻塞  等子线程1运行结束 并取得子线程结束的状态字

	printf("thread 1 exit code %d\n",ret);
	
	err = pthread_join(tid2,&ret);
	if(err!=0){
		printf("cant join with thread 2:%s\n",strerror(err));
	}

	printf("thread 2 exit code %d\n",ret);

	exit(0);
}
