#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <assert.h>
#include <unistd.h>

int main()
{
	const char *ip = "127.0.0.1";

	int port = 12345;

	struct sockaddr_in address;
	bzero(&address,sizeof(address));
	address.sin_family = AF_INET;

	inet_pton(AF_INET,ip,&address.sin_addr);
	address.sin_port = htons(port);

	socklen_t address_length = sizeof(address);
	int sockfd = socket(PF_INET,SOCK_DGRAM,0);

	char buffer[] = "hello,world\n";

	size_t ret = sendto(sockfd,buffer,strlen(buffer),0,(struct sockaddr*)&address,address_length);
	char recv_buffer[1024] = {0};
	ret = recvfrom(sockfd,recv_buffer,sizeof(recv_buffer),0,(struct sockaddr*)&address,&address_length);

	if(ret>0){
		printf("recvfrom server data:%s\n",recv_buffer);
	}

	return 0;
}
