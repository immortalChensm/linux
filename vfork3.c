#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int count = 1;
	int child;

	printf("count is :%d\n",count);

	if(!(child=vfork())){
		int i;
		for(i=0;i<100;i++){
			printf("this is son,the i is :%d\n",i);
			if(i==70){
				exit(1);
			}
			
		}
		printf("this is son,his pid is:%d,and the count is:%d\n",getpid(),++count);
		exit(1);
	}else{
		printf("after son,this is father,his pid is :%d and the count is:%d and child is :%d\n",getpid(),count,child);
	}

	return 0;
}
