#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t has_product = PTHREAD_COND_INITIALIZER;

struct msg{
	struct msg *next;
	int num;
};

struct msg *head;

void *customer(void *p)
{
	struct msg *mp;

	for(;;){
		pthread_mutex_lock(&lock);//加锁
		while(head == NULL){
			pthread_cond_wait(&has_product,&lock);//没有数据时  则阻塞
		}
		mp = head;
		head = mp->next;
		
		pthread_mutex_unlock(&lock);//解锁

		printf("customer %d\n",mp->num);

		free(mp);

		sleep(1);//阻塞
	}
}

void *product(void *p)
{
	struct msg *mp;

	for(;;){
		mp = malloc(sizeof(struct msg));
		mp->num = rand()%1000+1;
		printf("product %d\n",mp->num);

		pthread_mutex_lock(&lock);//加锁
		mp->next = head;
		head = mp;//保存产生的数据
		
		pthread_cond_signal(&has_product);//激活
		pthread_mutex_unlock(&lock);//释放锁  

		sleep(1);//阻塞
	}
}

int main()
{
	pthread_t pid,cid;

	pthread_create(&pid,NULL,&customer,NULL);
	pthread_create(&cid,NULL,&product,NULL);

	pthread_join(pid,NULL);
	pthread_join(cid,NULL);

	return 0;
}
