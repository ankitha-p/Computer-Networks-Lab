//client program

#include<rpc/rpc.h>
#include"date.h"

int main(int argc,char *argv[])
{
	CLIENT *cl;
	char **sresult;
	long *lresult;
	char *servername;
	servername=argv[1];
	cl=clnt_create(servername,DATE_PROG,DATE_VERS,"udp");
	lresult=bin_date_1(NULL,cl);
	sresult=str_date_1(lresult,cl);
	printf("Time: %ld seconds\n",*lresult);
	printf("Date: %s\n", *sresult);
	return 0;
}
