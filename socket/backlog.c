#include <sys/socket.h>
#include <netinet/in.h> //用于端口  的主机字节序转移为网络字节序
#include <arpa/inet.h> //用于IP地址转换函数

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <libgen.h>

static stop = 0;

static void handler_term(int sig)
{
	stop = 1;
}

int main(int argc,char *argv[])
{
	signal(SIGTERM,handler_term);

	if(argc<=3){
		printf("usage:%s ip_address port number backlog\n",basename(argv[0]));
		return 1;
	}

	const char *ip = argv[1];

	int port = atoi(argv[2]);
	int backlog = atoi(argv[3]);

	int sockfd = socket(PF_INET,SOCK_STREAM,0);

	assert(sockfd >=0);
	
	struct sockaddr_in address;
	bzero(&address,sizeof(address));
	address.sin_family = AF_INET;
	inet_pton(AF_INET,ip,&address.sin_addr);
	address.sin_port = htons(port);

	int ret = bind(sockfd,(struct sockaddr*)&address,sizeof(address));
	assert(ret!=-1);
	
	ret = listen(sockfd,backlog);
	assert(ret!=-1);

	while(!stop){
		sleep(1);
	}

	close(sockfd);

	return 0;
	
}
