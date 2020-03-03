#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handler(int num)
{
	printf("sigo is %d\n",num);
	return;
}

int main()
{
	struct sigaction act,oact;
		
	act.sa_handler = handler;
	act.sa_flags = 0;
	sigemptyset(&act.sa_mask);
	sigaddset(&act.sa_mask,3);//阻塞 SIGQUIT 在按键上是ctrl+\
	
	sigaction(2,&act,&oact);//捕获 SIGINT 中断信号   ctrl+c
	sigaction(3,&act,&oact);

	int i=10;
	while(i--){
		printf("this is \n");
		if(i==5){
			sigaction(2,&oact,NULL);
			oact.sa_handler = SIG_IGN;//到达5后修改  信号3的动作为默认行为 并且不在阻塞
			sigaction(3,&oact,NULL);
		}

		sleep(1);
	}

	return 0;
}
