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

	attr.mq_maxmsg = 3;
	attr.mq_msgsize = 8192;

	char *name = "/temp.mq";

	mqd_t mqd = mq_open(name,O_RDWR|O_CREAT|O_EXCL,0777,&attr);

	if(mqd==-1){
		perror("open failed");
		//exit(EXIT_FAILURE);

		mqd = mq_open(name,O_RDWR);
		if(mqd == -1){
			perror("open failed");
			exit(EXIT_FAILURE);
		}
	}

	printf("mqd=%d,mq_open %s success\n",mqd,name);

	int ret = mq_getattr(mqd,&attr);
	printf("mq_getattr ret=%d\n",ret);

	printf("max msg=%ld,max bytes=%ld,currently=%ld\n",attr.mq_maxmsg,attr.mq_msgsize,attr.mq_curmsgs);

	if(mq_close(mqd)!=-1){
		printf("mq_close %s success\n",name);
	}

	sleep(20);

	if(mq_unlink(name)!=-1){
		printf("mq_unlink %s success\n",name);
	}

	return 0;
}
