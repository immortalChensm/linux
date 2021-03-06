#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <assert.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#define _GNU_SOURCE
#define __USE_GNU
int main(int argc,char *argv[])
{
	if(argc<=2){
		printf("useage:%s ip_address port_number\n",basename(argv[0]));
		return 1;
	}

	const char *ip = argv[1];
	int port = atoi(argv[2]);

	struct sockaddr_in address;
		
	bzero(&address,sizeof(address));
	address.sin_family = AF_INET;
	inet_pton(AF_INET,ip,&address.sin_addr);
	address.sin_port = htons(port);

	int sock = socket(PF_INET,SOCK_STREAM,0);
	assert(sock>=0);

	int ret = bind(sock,(struct sockaddr*)&address,sizeof(address));
	assert(ret!=-1);

	struct sockaddr_in client;

	socklen_t client_addrlenght = sizeof(client);
	
	int connfd = accept(sock,(struct sockaddr*)&client,&client_addrlenght);
	if(connfd<0){
		printf("errno is:%d\n",errno);
	}else{
		int pipefd[2];

		assert(ret!=-1);

		ret = pipe(pipefd);

		ret = splice(connfd,NULL,pipefd[1],NULL,123456,SPLICE_F_MORE);
		assert(ret!=-1);

		ret = splice(pipefd[0],NULL,connfd,NULL,123456,SPLICE_F_MORE);

		assert(ret!=-1);
		close(connfd);
	}

	close(sock);

	return 0;
}
