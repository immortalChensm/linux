#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	struct mq_attr attr;

	attr.mq_maxmsg = 24;
	attr.mq_msgsize = 8192;

	char *name = "/temp.mq";

	mqd_t mqd = mq_open(name,O_RDWR|O_CREAT|O_EXCL,0777,&attr);

	if(mqd==-1){
		perror("create failed");
		
		mqd = mq_open(name,O_RDWR);

		if(mqd == -1){
			perror("open failed");
			exit(EXIT_FAILURE);
		}
	}

	printf("mq_open %s success\n",name);

	mq_getattr(mqd,&attr);

	printf("max msg=%ld,max_bytes=%ld,currently=%ld\n",attr.mq_maxmsg,attr.mq_msgsize,attr.mq_curmsgs);

	char *msg_ptr1 = "hello china";
	char *msg_ptr2 = "hello japanese";
	char *msg_ptr3 = "hello american";

	size_t msg_len1 = strlen(msg_ptr1);
	size_t msg_len2 = strlen(msg_ptr2);
	size_t msg_len3 = strlen(msg_ptr3);

	mq_send(mqd,msg_ptr1,msg_len1,1);
	mq_send(mqd,msg_ptr2,msg_len2,2);
	mq_send(mqd,msg_ptr3,msg_len3,3);

	printf("mq_send success\n");

	if(mq_close(mqd)!=-1){
		printf("mq_close %s success\n",name);
	}

	return 0;
}
