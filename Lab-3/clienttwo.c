#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<stdlib.h>
int main(int argc, char *argv[])
{
	int cli_sfd, nbytes;
	socklen_t addr_size;
	char buffer[1024];
	struct sockaddr_in sa, ca;
	cli_sfd = socket(AF_INET, SOCK_DGRAM, 0);	//create UDP socket
	sa.sin_family = AF_INET;			//Fill the server address structure
	sa.sin_port = htons(atoi(argv[1]));
	sa.sin_addr.s_addr = inet_addr("172.20.1.171");
	memset(sa.sin_zero, '\0', sizeof(sa.sin_zero)); 
	
	/*ca.sin_family = AF_INET;			//Fill the client address structure
	ca.sin_port = 0;				//UDP will assign a free port number
	ca.sin_addr.s_addr = htonl(INADDR_ANY);		//Machine's IP address on which we run
	memset(ca.sin_zero, '\0', sizeof(ca.sin_zero));
	*/
	bind(cli_sfd,(struct sockaddr*)&ca,sizeof(ca)); //Client registration with UDP
	addr_size = sizeof(sa);
	while(1){
		write(1,"CLIENT> ", 8);		//prompt the user to enter a message
		fgets(buffer,1024,stdin);	 /*Send message to server*/
		sendto(cli_sfd,&buffer,sizeof(buffer), 0, (struct sockaddr *) &sa, addr_size);
		//*Receive message from server
		if(strncmp(buffer,"bye",3)==0)break;
		nbytes=recvfrom(cli_sfd, &buffer,1024,0, (struct sockaddr *) &sa, &addr_size);
		buffer[nbytes]='\0';
		printf("SERVER> %s\n",buffer);
	}
	close(cli_sfd);
	return 0;
}
