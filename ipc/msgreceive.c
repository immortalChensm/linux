#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char *name = "/temp.mq";

	mqd_t mqd = mq_open(name,O_RDWR);

	if(mqd == -1){
		perror("open failed");
		exit(EXIT_FAILURE);
	}

	printf("mq_open %s success\n",name);

	struct mq_attr attr;

	if(mq_getattr(mqd,&attr)==-1){
		perror("mq_getattr failed");
		exit(EXIT_FAILURE);
	}

	char *msg_ptr;

	size_t msg_len = attr.mq_msgsize;

	unsigned msg_prio;

	msg_ptr = (char*)malloc(msg_len);

	while(1){
		bzero(msg_ptr,msg_len);

		int res = mq_receive(mqd,msg_ptr,msg_len,&msg_prio);
		if(res!=-1){
			printf("msg is:%s,msg_prio:%d\n",msg_ptr,msg_prio);
		}else{
			perror("mq_receive failed");
			break;
		}
	}

	if(mq_close(mqd)!=-1){
		printf("mq_close %s success\n",name);
	}

	return 0;
}
