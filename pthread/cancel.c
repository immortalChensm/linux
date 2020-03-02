#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *thread_func(void *arg)
{
	int *val = arg;
	printf("hi,i am a thread!\n");
	if(NULL!=arg){
		while(1){
			printf("argument set:%d\n",*val);
		}
	}
}

int main(void)
{
	pthread_t tid;
	int t_arg=10;
	if(pthread_create(&tid,NULL,thread_func,&t_arg)){
		perror("fail to create thread");
	}
	
	sleep(1);//让子线程先运行  主线程阻塞着
	printf("main thread!\n");

	//子线程虽然一直在运行，但在主线程里，可以取消子线程
	printf("准备取消子线程的运行\n");
	pthread_cancel(tid);

	return 0;

	
}
