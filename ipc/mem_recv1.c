#include <sys/mman.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
typedef struct {
	char name[4];

	int age;
}people;

main(int argc,char *argv[])
{
	int fd,i;

	people *p_map;

	fd = open(argv[1],O_CREAT|O_RDWR,0777);

	p_map = (people*)mmap(NULL,sizeof(people)*10,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);

	for(i=0;i<10;i++){
		printf("name:%s age %d\n",(p_map+i)->name,p_map[i+1].age);
	}

	munmap(p_map,sizeof(people)*10);
}