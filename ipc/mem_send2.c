#include <stdio.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
typedef struct {
	//char name[10];
	//char mobile[12];
	int age;
}people;

void main(int argc,char *argv[])
{
	
	int fd,i;
	people *p_map;
	fd = open(argv[1],O_CREAT|O_RDWR|O_TRUNC,00777);
	if(fd<3){
		fprintf(stderr,"%s\n",strerror(errno));
		exit(0);
	}

	//lseek(fd,sizeof(people)*5-1,SEEK_SET);
	//write(fd,"",1);
	p_map = (people*)mmap(NULL,sizeof(people)*10,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
	
	if(p_map == MAP_FAILED){
		perror("mmap error");
		exit(0);
	}else{
		printf("ok\n");
	}
	char temp = 'a';
	printf("fd=%d,p_map=%#X\n",fd,p_map);
	printf("person=%#X\n",sizeof(people));
	for(i=0;i<10;i++){
		//temp+=1;
		(p_map+i)->age = i;
	//	(*(p_map+i)).age = i;
	//	printf("%#X,%#X\n",p_map+i,(p_map+i)->name+1);
	//	strcpy((p_map+i)->name,"china");
	//	(*(p_map+i)).age = i;
		//(p_map+i)->age = i;
	//	memcpy((*(p_map+i)).name,"china",6);
	//	memcpy((*(p_map+i)).mobile,"18894651245",12);
	}

	close(fd);

	sleep(1);

	printf("write ok\n");

	munmap(p_map,sizeof(people)*10);

	
}
