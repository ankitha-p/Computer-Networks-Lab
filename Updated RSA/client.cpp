#include <iostream>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

string compute(string msg,int key,int n)
{
    string str="";
    for(int i=0;i<msg.length();i++)
    {
        int count=0, val=1,c=int(msg[i]-'0');
        cout<<c;
        while(count++<key)	val=(val*c)%n;
        str=str+ char(val%n+'0');
    }
    return str;
}

int main(int argc, char* argv[])
{
	string  msg;
		cout<<"\nEnter the number message:";
		cin>>msg;
	int sfd, si, nb, i;
	string buf;
	struct sockaddr_in servaddr;

	sfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sfd<0)	{		perror("socket() error!");	}
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(atoi(argv[1]));
	servaddr.sin_addr.s_addr = inet_addr("172.17.0.8");

	si = connect(sfd, (struct sockaddr*)&servaddr, sizeof(servaddr));

	if(si<0)	{	perror("connect() error!");	return 0;}
	else
	{
		cout<<"Connected!";

		int e,n;
		cout<<"Receiving data"<<endl;

		char ch[100];

		if((nb= recv(sfd, ch, 10,0))<0) {perror("recv()");return -1;}
		n=atoi(ch);

		if((nb = recv(sfd, ch, 10,0))<0){perror("recv()");return -1;}

		e=atoi(ch);
		cout<<n<<"\t"<<e<<endl;


		string c=compute(msg,e,n);

		cout<<c<<endl;

		cout<<"Send?"<<endl;
		char che;
		cin>>che;
		char *m=const_cast<char*>(c.c_str());
		nb=send(sfd, m, sizeof(m), 0);
		if(nb<0) perror("send()");
		close(sfd);

	}

	return 0;
}

