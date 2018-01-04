#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
int main(int argc, char *argv[])
{
	int ser_sfd,nbytes,i,addr_len,len;
	char buffer[1024];
	struct sockaddr_in sa,ca;

	ser_sfd=socket(AF_INET, SOCK_DGRAM, 0);//Create UDP sockets

	sa.sin_family =AF_INET;	//Fill the server address structure
	sa.sin_port =htons(atoi(argv[1]));
	sa.sin_addr.s_addr =inet_addr("172.20.0.161");
	len=sizeof(sa);

	bind(ser_sfd, (struct sockaddr *) &sa,len);//register server address
	addr_len= sizeof(ca);
	//Client server interaction using UDP protocol
	while(1)
	{
		nbytes=recvfrom(ser_sfd,&buffer,1024,0,(struct sockaddr *)&ca,&addr_len);
		write(1,"CLIENT>",8);
		printf("%s\n",buffer);		//display the message received from client
		buffer[nbytes]='\0';		 
		if((strncmp(buffer,"bye",3))==0)break;
		write(1,"SERVER> ",9);		//prompt the user to enter a message
		fgets(buffer,1024,stdin);	//read a message from keyboard
		sendto(ser_sfd,&buffer,nbytes,0,(struct sockaddr *)&ca,addr_len);//Send server's message to client
	}
	close(ser_sfd);
	return 0;
}
