#include<stdio.h>
int main()
{
	char buff[20];
	fgets(buff,20,stdin);
	printf("\n**%d**%s\n",strcmp(buff,"hai"),buff);
	return 0;
}
