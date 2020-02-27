#include <stdio.h>
#include <stdlib.h>

int main()
{
	int status;

	if((status=system("date"))<0){
		perror("system error\n");
		exit(0);
	}

	printf("exit status=%d\n",status);
	
	status = system("php -v");
	
	status = system("php demo.php");

	return 0;
}
