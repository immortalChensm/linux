#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

pthread_key_t key;

void echomsg(void *param)
{
	printf("destructor excuted in thread %lu,param=%lu\n",pthread_self(),*((unsigned long int*)param));
}
void *child1(void *param)
{
	unsigned long int tid = pthread_self();
	printf("child1 thread %lu enter\n",tid);

	pthread_setspecific(key,(void*)tid);
	sleep(2);

	unsigned long int val = *((unsigned long int*)pthread_getspecific(key));

	printf("child1 thread %lu returns %lu\n",tid,val);
	
	sleep(2);

	return (void*)0;
}

void *child2(void *param)
{
	//线程2运行时  指定key的值  此时阻塞当前线程
	unsigned long int tid = pthread_self();
	printf("child2 run thread %lu enter\n",tid);
	pthread_setspecific(key,(void*)tid);

	sleep(1);
	//阻塞结束时从指定的key获取到值
	unsigned long int val = *((unsigned long int*)pthread_getspecific(key));
	printf("child2 thread %lu returns %lu\n",tid,val);
	sleep(5);
	return (void*)0;
}

int main()
{
	pthread_t tid1,tid2;
	printf("main thread enter\n");
	//TSD 一键多值  对不同的线程拥有不同的值
	pthread_key_create(&key,echomsg);

	//创建2个子线程
	pthread_create(&tid1,NULL,child1,NULL);
	pthread_create(&tid1,NULL,child2,NULL);

	//控制主线程阻塞  
	sleep(10);

	pthread_key_delete(key);
	printf("main thread exit\n");

	return 0;
}
