#include<stdio.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<stdlib.h>
#define COUNT 5
int main(int argc, char *argv[]) 
{ 
	int sfd,newsfd,s,len,n,i,count=COUNT;
	 char buff[100],ch='*'; 
	struct sockaddr_in servaddr, ca,client; 
	sfd=socket(AF_INET, SOCK_STREAM,0);	//creates a socket
	if(sfd<0) 
	{ 
		perror("socket() error:"); 
		exit(-1);
	} 
	servaddr.sin_family=AF_INET; 
	servaddr.sin_port=htons(atoi(argv[1])); 	//convert port address given from command line into network byte order
	servaddr.sin_addr.s_addr=htonl(INADDR_ANY);	//extracts the machine IP address 
	//servaddr.sin_addr.s_addr=inet_addr("172.16.0.100"); 
	s=bind(sfd,(struct sockaddr*)&servaddr,sizeof(servaddr));	//bind the server with the specified address
	if(s<0) 
	{ 
		perror("bind() error:"); 
		exit(-1);
	} 
	s=listen(sfd,5);	//tells its readiness to TCP
	if(s<0) 
	{ 
		perror("listen() error:"); 
		exit(-1);
	} 
	printf("Server is ready and waiting for client requests...........\n"); 
	newsfd=accept(sfd,(struct sockaddr*)&ca,&len); 	//server blocks fr connection request
	if(newsfd<0) 
	{ 
		perror("accept() error:"); 
		exit(-1); 
	} 
	printf("Connected to client........"); 
	while(count>0){
		n=recv(newsfd,&buff,100,0); 	//reads data into ‘buff’ from the scoket
	
		buff[n]='\0';
		printf("\nMessage from client: %s",buff); //displays the data on to the terminal 
		ch='*';
		for(i=0;ch!='\n';++i){scanf("%c",&ch);
			buff[i]=ch;} //converts the data in the ‘buff’ to  upper case 
		send(newsfd,&buff, n,0); //writes the data from ‘buff’ over to  socket. 
		count--;
	}
	close(sfd);
	close(newsfd);   //close the connection 
	return 0; 
} 

