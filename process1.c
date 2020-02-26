#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
	printf("the current process Id is %d\n",getpid());
	printf("the father process id is %d\n",getppid());
	printf("the user true Id is %d\n",getuid());
	printf("the valid user Id is %d\n",geteuid());
	printf("the group Id is %d\n",getgid());
	printf("the valid group Id is %d\n",getegid());

	return 0;
}
