#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mqueue.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	char *name="/temp1.mq";

	mqd_t mqd = mq_open(name,O_RDWR);

	printf("mqd=%d\n",mqd);
	if(mqd!=-1){
	struct mq_attr attr;

	mq_getattr(mqd,&attr);

	printf("maxmsg=%d,msgsize=%d\n",attr.mq_maxmsg,attr.mq_msgsize);

	char *msg = (char*)malloc(attr.mq_msgsize*sizeof(char));
	unsigned int mq_prio;	
	int ret = mq_receive(mqd,msg,attr.mq_msgsize,&mq_prio);

	printf("ret=%d\n",ret);

	if(ret){
		printf("msg=%s\n",msg);
	}

	
	
	}

	mq_close(mqd);

	return 0;
	
}
