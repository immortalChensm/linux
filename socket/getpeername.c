#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <fcntl.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string.h>
#include <libgen.h>
#include <unistd.h>
#include <errno.h>
#include <assert.h>

int main(int argc,char *argv[])
{
	if(argc<2){
		printf("useage:%s ip and port_number\n",basename(argv[0]));
		return 0;
	}

	const char *ip = argv[1];
	int port = atoi(argv[2]);

	struct sockaddr_in address;
	bzero(&address,sizeof(address));

	address.sin_family = AF_INET;

	inet_pton(AF_INET,ip,&address.sin_addr);

	address.sin_port = htons(port);

	int sockfd = socket(PF_INET,SOCK_STREAM,0);
	assert(sockfd!=-1);

	int ret = bind(sockfd,(struct sockaddr*)&address,sizeof(address));
	assert(ret!=-1);

	ret = listen(sockfd,5);

	struct sockaddr_in client;
	socklen_t client_length = sizeof(client);
	int connfd = accept(sockfd,(struct sockaddr*)&client,&client_length);

	if(connfd>0){
		
		char remote[INET_ADDRSTRLEN];

		char recvmsg[1024] = {0};

		int ret = recv(connfd,recvmsg,sizeof(recvmsg),0);
		send(connfd,"hello",5,0);
		if(ret>0){
			printf("data:%s\n",recvmsg);
		}

		printf("remote ip:%s,port:%d\n",inet_ntop(AF_INET,&client.sin_addr,remote,INET_ADDRSTRLEN),ntohs(client.sin_port));
		bzero(&client,sizeof(client));
		ret = getpeername(connfd,(struct sockaddr*)&client,&client_length);

		printf("getpeername ret=%d\n",ret);
	}

	close(sockfd);
	close(connfd);

	return 0;
}
