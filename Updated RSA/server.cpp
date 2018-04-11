#include <iostream>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>

using namespace std;

int getGcd ( int a, int h)
{
	int temp;
	while(1)
	{
		temp = a%h;
		if(temp==0)	return h;
		a = h;
		h = temp;
	}
}

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

	int  p,q;
	cout<<"Enter two prime numbers: ";		//2 random prime numbers
	cin>>p>>q;

	int  n=p*q;
	int  phi = (p-1)*(q-1);

	int  e=2, gcd;

	while(e<phi)   					//pick an e (1<e<phi) such that gcd(e,phi)=1
	{
		gcd = getGcd(e,phi);
		if(gcd==1)	break;
		else		e++;
	}

	int  d=1, s;

	while(1)
	{
		int s = (d*e) % phi;
		if(s==1)	 break;
		else d++;
	}
	char ne[10],en[10];
	//itoa(n,ch,10);
	sprintf(ne,"%d",n);

	sprintf(en,"%d",e);
	cout<<"Starting..."<<endl;

	int sfd, newsfd, si, nb, i,j;
	string buf;
	struct sockaddr_in servaddr, clientacc;
    int len;
	sfd = socket(AF_INET, SOCK_STREAM, 0);
	socklen_t size;
	if(sfd<0)
	{
		printf("socket() error!");
		//exit(-1);
	}
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(atoi(argv[1]));
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	si = bind(sfd, (struct sockaddr*)&servaddr, sizeof(servaddr));

	if(si<0)	{	printf("bind() error!");}

	si = listen(sfd, 5);

	if(si<0)	{		printf("listen() error!");	}
    size=sizeof(servaddr);
	printf("\n---SERVER WAITING FOR CLIENT REQUEST---");

	newsfd = accept(sfd, (struct sockaddr *)&servaddr,&size);
	if(newsfd<0)	{	printf("accept() error!");return 0;	}
	else
	{
		printf("\n---CONNECTED TO CLIENT---");

		char ch[100];

		cout<<"received is"<<ch<<endl;
		cout<<"Starting actual program.."<<endl;

		nb=send(newsfd, ne,sizeof(ne) , 0);
		if(nb==-1){perror("send()");}

		nb=send(newsfd, en,sizeof(en) , 0);
		if(nb==-1){perror("send()");}

		if((nb = recv(newsfd, ch, 10, 0))<0) {perror("recv()!");return 0;}

		cout<<"received is"<<ch<<endl;

		string m=compute(ch,d,n);

		//cout<<"\nMessage data = "<<msg;
		cout<<"\nP: \t"<<p<<"\tQ:\t"<<q;
		cout<<"\n"<<"n = p*q = "<<n;
		cout<<"\n"<<"Phi(n) = "<<phi;
		cout<<"\n"<<"e = "<<e;
		cout<<"\n"<<"d = "<<d;

		cout<<"\n"<<"Original Message sent = "<<m<<endl;

		close(sfd);
		close(newsfd);

	}

	return 0;
}
