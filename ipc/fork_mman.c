#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char address[50];
	char name[30];
}person;


int main(int argc,char *argv)
{
	int fd,i;

	person *tony;

	tony = (person*)mmap(NULL,sizeof(person)*2,PROT_READ|PROT_WRITE,MAP_SHARED|MAP_ANONYMOUS,-1,0);	

	if(tony == MAP_FAILED){
		perror("mmap error");
		return 0;
	}

	pid_t pid = fork();

	if(pid == 0){

		sleep(2);

		for(i=0;i<2;i++){

			printf("pid=%d get data\n",getpid());
			printf("%s-%s\n",(tony+i)->address,(tony+i)->name);
		}

		munmap(tony,sizeof(person)*2);

		exit(0);
	}

	for(i=0;i<2;i++){
		printf("pid=%d write data\n",getpid());
		strcpy((tony+i)->address,"guiyang");
		memcpy((tony+i)->name,"tony",5);
	}

	sleep(5);

	printf("%s\n",tony[0].name);

	munmap(tony,sizeof(person)*2);
	return 0;
	
}
