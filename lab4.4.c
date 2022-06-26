#include<unistd.h>
#include<arpa/inet.h>
#include <stdio.h> 
#include <netdb.h> 
#include <netinet/in.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <sys/types.h> 
#include <signal.h>

void func(int sockfd) 
{ 
	char buff[80]; 
	int n; 
	for (;;) { 
		bzero(buff, sizeof(buff)); 
		printf("You:   : "); 
		n = 0; 
		while ((buff[n++] = getchar()) != '\n'); 
		write(sockfd, buff, sizeof(buff)); 
		bzero(buff, sizeof(buff)); 
		read(sockfd, buff, sizeof(buff)); 
		printf("Server: %s", buff); 
		if ((strncmp(buff, "exit", 4)) == 0) { 
			printf("\nClient Exiting...\n"); 
			printf("--Chatting Room-- \n\n"); 
			break; 
		} 
		
	} 
} 

int main() 
{ 
	int sockfd, connfd; 
	struct sockaddr_in servaddr, cli; 
 
	sockfd = socket(AF_INET, SOCK_STREAM, 0); 
	if (sockfd == -1) { 
		printf("Socket creation failed.\n"); 
		exit(0); 
	} 
	else
		printf("Socket successfully created.\n"); 
	bzero(&servaddr, sizeof(servaddr));

	printf("Enter IP Server Address \n>>> ");
	char ipserver[20];
	scanf("%s", ipserver);
	servaddr.sin_family = AF_INET;  
	servaddr.sin_addr.s_addr = inet_addr(ipserver); 
	servaddr.sin_port = htons(8888); 
 
	if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) != 0) { 
		printf("Connection to the server was unsuccessful.\n"); 
		exit(0); 
	} 
	else {
		printf("In contact with the server. Awaiting a response...\nPress [CTRL + C] to quit anytime\n\n----------CHAT----------\n"); 
	}

	func(sockfd); 

	close(sockfd); 

} 
