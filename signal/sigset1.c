#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void printsigset(sigset_t *sig)
{
	int i;
	for(i=0;i<32;i++){
		if(sigismember(sig,i)){
			printf("%d=1-",i);
		}else{
			printf("%d=0-",i);
		}
	}
	printf("\n");
}

int main()
{
	sigset_t s,p;
	sigemptyset(&s);

	sigemptyset(&p);

	sigaddset(&s,SIGTSTP);
	sigprocmask(SIG_BLOCK,&s,NULL);
	printf("打印阻塞的信号集\n");
	printsigset(&s);
	while(1){
		sigpending(&p);
		printsigset(&p);
		sleep(1);
	}

	return 0;
}
