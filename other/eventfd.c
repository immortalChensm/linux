#include <sys/eventfd.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#define handle_error(msg) \
	do {perror(msg);exit(EXIT_FAILURE);} while(0)

int main(int argc,char *argv[])
{
	uint64_t u;
	int j;
	int efd = eventfd(10,0);

	if(efd==-1){
		handle_error("eventfd");
	}

	int ret = fork();

	if(ret==0){
		for(j=1;j<argc;j++){
			printf("child writing %s to efd\n",argv[j]);

			u = atoll(argv[j]);

			ssize_t s = write(efd,&u,sizeof(uint64_t));
			if(s!=sizeof(uint64_t)){
				handle_error("write");
			}
		}

		printf("child completed write loop\n");
		

		exit(EXIT_SUCCESS);
	}else{
		sleep(2);

		ssize_t s = read(efd,&u,sizeof(uint64_t));

		if(s!=sizeof(uint64_t)){
			handle_error("read");
		}

		printf("parent read %llu from efd\n",(unsigned long long)u);

		exit(EXIT_SUCCESS);
	}
}
