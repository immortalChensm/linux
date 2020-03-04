#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <mqueue.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc,char *argv[])
{
	
	char *name = "/temp1.mq";

	struct mq_attr attr;
	
	attr.mq_maxmsg=3;
	attr.mq_msgsize = 8192;

	mqd_t mqd = mq_open(name,O_RDWR|O_CREAT|O_EXCL,0777,&attr);
	printf("mqd=%d\n",mqd);

	if(mqd==-1){
		mqd = mq_open(name,O_RDWR);
	}	
	if(mqd>0){
		
		mq_send(mqd,argv[1],strlen(argv[1]),0);
	}

	
	mq_close(mqd);

	return 0;

}
