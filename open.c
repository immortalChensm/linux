#include <stdio.h>
#include <stdlib.h>
//#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main()
{
	int temp;
	temp = open("open_example.txt",O_RDWR|O_CREAT,S_IRWXU|S_IRWXG);
	printf("%d\n",temp);
	temp = close(temp);
	printf("%d\n",temp);
	return 0;
}
