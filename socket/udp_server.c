#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <errno.h>
#include <unistd.h>
#include <assert.h>
#include <string.h>
int main()
{
	const char *ip = "0.0.0.0";
	int port = 12345;
	printf("udp server %d\n",getpid());
	struct sockaddr_in address;
	bzero(&address,sizeof(address));
	address.sin_family = AF_INET;
	inet_pton(AF_INET,ip,&address.sin_addr);
	address.sin_port = htons(port);

	int sockfd = socket(PF_INET,SOCK_DGRAM,0);

	assert(sockfd>=0);

	int ret = bind(sockfd,(struct sockaddr*)&address,sizeof(address));
	assert(ret!=-1);

	struct sockaddr_in client;
	bzero(&client,sizeof(client));
	socklen_t client_len = sizeof(client);
	char buffer[1024] = {0};
	
	while(1){
		
		size_t ret = recvfrom(sockfd,buffer,sizeof(buffer),0,(struct sockaddr*)&client,&client_len);

		if(ret>0){
			printf("data=%s\n",buffer);
			char remote[INET_ADDRSTRLEN];
			inet_ntop(AF_INET,&client.sin_addr,remote,INET_ADDRSTRLEN);
			int client_port;
			client_port = ntohs(client.sin_port);
			printf("client ip:%s/%d\n",remote,client_port);
		}

	//	memset(buffer,'\0',sizeof(buffer));

		ret = sendto(sockfd,buffer,ret,0,(struct sockaddr*)&client,client_len);

		printf("ret=%d\n",ret);
	}

	return 0;
}
