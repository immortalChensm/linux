#include <pthread.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

void *func(void *arg)
{
	pthread_detach(pthread_self());
	int fd = open("detach_demo1.txt",O_RDWR|O_CREAT|O_APPEND,S_IRWXU);
	if(fd<=0){
		perror("子线程无法创建文件");	
		return ((void*)1);
	}
	write(fd,arg,strlen(arg));
	close(fd);
	printf("fd %d write over\n",fd);
	return ((void*)1);
}
int main(void)
{
	pthread_t tid;
		
	int ret = pthread_create(&tid,NULL,func,(char*)"hello,world!");
	if(ret!=0){
		perror("pthread create error");
		return 1;
	}else{
		sleep(1);
	//	pthread_detach(tid);
	}

	printf("main thread run over\n");

	return 0;
	
}
