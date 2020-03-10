#include <stdio.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
typedef struct {
//	char name[10];
//	char mobile[11];
	int age;
}people;

void main(int argc,char *argv[])
{
	
	int fd,i;
	people *p_map;

	fd = open(argv[1],O_RDWR);

	p_map = (people*)mmap(NULL,sizeof(people)*10,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);

	for(i=0;i<10;i++){
		
		printf("%d\n",p_map[i].age);
	}

	close(fd);

	munmap(p_map,sizeof(people)*10);
}
