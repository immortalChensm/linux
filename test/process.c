#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>

#define FAILURE -1
#define u8 unsigned char
#define u16 unsigned short
#define SIZE_NAME_NORMAL 48
#define SIZE_NAME_LOG 48
#define SUCCESS 0
#define CLOSE_FD(x) (close(x))
#define FREE_POINTER(x) (free(x))
#define __offset(pinst) ((pinst)->proc[(pinst)->process_idx])
#define __round_robin(pinst,roll) ((pinst)->proc[((roll)%(pinst)->process_num)+1].pipefd[1]

typedef struct process
{
	char name[SIZE_NAME_NORMAL];
	pid_t pid;
	int pipefd[2];
	size_t score;
}process_t;

typedef struct instance
{
	char prg_name[SIZE_NAME_LOGN];	
	char cfg_name[SIZE_NAME_LONG];
		
	u16 process_num;
	u16 process_idx;

	struct process *proc;
}instance_t;

static u8 g_enable;

static void __sig_quit(int sig)
{
	g_enable = 0;
}

static int __master(instance_t *pinst)
{
	int ret = 0;
	int fd = 0;
	int ix = 0;
	int roll = 0;

	char c = 0;

	printf("master #%u setup\n",pinst->process_idx);

	for(g_enable=1;g_enable;){
		fd = __round_robin(pinst,++roll);

		c = 'A'+roll%3;

		ret = write(fd,&c,1);

		if(ret<=0){
			return FAILURE;
		}

		sleep(1);
	}

	for(ix=1;ix<=pinst->process_num;ix++){
		c = 'Q';
		write(__round_robin(pinst,++roll),&c,1);
	}

	printf("master#%u shutdown\n",pinst->process_idx);
	return SUCCESS;
}

static int __worker(instance_t *pinst)
{
	int fd = __offset(pinst).pipefd[0];

	int ix = 0;

	size_t read_byte = FAILURE;

	char buffer[1024] = {0};

	printf("worker#%u setup\n",pinst->process_idx);

	for(g_enable=1;g_enable;){
		printf("work read after....\n");
		read_byte = read(fd,buffer,sizeof(buffer));
		if(read_byte<=0){
			if(errno == EAGAIN || errno == EINTR){
				continue;
			}
			return FAILURE;
		}

		for(ix=0;ix<read_byte;ix++){
			switch(buffer[ix]){
				case 'A':
				case 'B':
				case 'C':
					__offset(pinst).score+=buffer[ix];
					printf("worker#%u recv command:%c,score:%llu\n",pinst->process_idx,buffer[ix],__offset(pinst).score);
					break;
				case 'Q':
					printf("quit\n");
					g_enable=0;
					break;
				default:
					break;
			}
		}
	}

	printf("worker#%u shutdown\n",pinst->process_idx);

	return SUCCESS;
}


int process_poll(instance_t *pinst,u16 process_num)
{
	int ret = FAILURE;
	int ix = 0;
	int status = 0;

	if(!pinst||!process_num){
		printf("NULL\n");
		goto _E1;
	}

	signal(SIGINT,__sig_quit);

	signal(SIGTERM,__sig_quit);

	pinst->process_idx = 0;

	pinst->process_num = process_num;

	pinst->proc = (process_t)calloc(process_num+1,sizeof(process_t));

	if(!pinst->proc){
		printf("alloc process poll struct failed\n");
		goto _E1;
	}

	for(ix=1;ix<=process_num;ix++){
		
		int bufsize = 1;

		ret = pipe(pinst->proc[ix].pipefd);

		if(SUCCESS!=ret){
			printf("socketpair\n");
			goto _E2;
		}
		printf("setup worker#%u\n",ix);

		pinst->proc[ix].pid = fork();

		
		if(pinst->proc[ix].pid <0){
			printf("fork\n");
			goto _E2;
		}

		else if(pinst->proc[ix].pid >0){
			CLOSE_FD(pinst->proc[ix].pipefd[0]);
			printf(".......\n");
			continue;
		}else{
			
			CLOSE_FD(pinst->proc[ix].pipefd[1]);
			printf("xxxxx\n");
			pinst->process_idx = ix;
			ret = __worker(pinst);

			goto _E2;
		}
	}

	ret = __master(pinst);

	for(ix=1;ix<=pinst->process_num;ix++){
		waitpid(pinst->proc[ix].pid,&status,WNOHANG);
	}
_E2:
	for(ix=1;ix<=pinst->process_num;ix++){
		CLOSE_FD(pinst->proc[ix].pipefd[1]);
		CLOSE_FD(pinst->proc[ix].pipefd[0]);
	}

	FREE_POINTER(pinst->proc);
_E1:
	return ret;
}
int main(int argc,char *argv[])
{
	instance_t inst = {0};

	if(argc<2){
		printf("usage:%s process number\n",argv[0]);
		return EXIT_FAILURE;
	}

	return process_poll(&inst,atoi(argv[1]));
}
