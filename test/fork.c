#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
static char *names[20];//静态变量放全局数据区

static char address[3][50];
int main(int argc,char *argv[])
{
	//static char address[3][50];
//	address[0] = "china";
	strcpy(address[0],"china");

	int age[100],i;

	printf("start");
        
	printf("pid=%d\n",getpid());

	pid_t pid = fork();

	if(pid==0){
		i=0;
	//	address[2] = "amercian";
		strcpy(address[2],"american");
		while(1){
			//names[0] = "lucy";
			//names[1] = "tom";
			printf("[tony] child process %d=%d i=%d=%s\n",getpid(),getpgid(getpid()),i,address[i]);
			i++;
			sleep(2);
			if(i>2)i=0;
		
		}
		exit(0);
	}
	setpgid(pid,getpid());
   	pid = fork();
	if(pid==0){
	
	//	address[1] = "japanese";	
		strcpy(address[1],"japanese");
		i=0;
		while(1){
			printf("[tom] child process %d=%d i=%d=%s\n",getpid(),getpgid(getpid()),i,address[i]);
			i++;
			sleep(2);
			if(i>2)i=0;
		}
		exit(0);
	}
	setpgid(pid,getpid());
	int exitcode;
	printf("haha\n");
	printf("pid=%d\n",getpid());
	pid=wait(&exitcode);
	i=0;
	while(1){
		printf("%s\n",address[i]);
		i++;
	}	
	printf("pid %d is over\n",pid);
	return 0;
}
