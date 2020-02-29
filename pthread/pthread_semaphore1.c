#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

sem_t cook_number,eat_number;

int number=0;
void *cook(void *arg)
{
	while(1){
		sem_wait(&cook_number);//P 操作 减1操作  如果不能减1操作就会阻塞  
		printf("准备做饭\n");
		number++;
		printf("做了%d碗饭\n",number);
		
		sem_post(&eat_number);//V 操作  加1操作  以便其它线程有机会运行

		sleep(1);
	}	
}

void *eat(void *arg)
{
	while(1){
		sem_wait(&eat_number);
		printf("有饭吃了\n");
		printf("我吃%d碗饭\n",number);
		sem_post(&cook_number);

		sleep(1);
	}
}

int main()
{

	pthread_t tidc,tide;
	sem_init(&cook_number,0,1);
	sem_init(&eat_number,0,0);
	pthread_create(&tidc,NULL,cook,NULL);
	pthread_create(&tide,NULL,eat,NULL);

	pthread_join(tidc,NULL);
	pthread_join(tide,NULL);

	sem_destroy(&cook_number);
	sem_destroy(&eat_number);

	return 0;
}
