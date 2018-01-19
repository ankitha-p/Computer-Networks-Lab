#include<stdio.h>
#include<math.h>
struct node
{
	unsigned dist[20];
	unsigned from[20];
}rt[10];

int main()
{
	int costmat[20][20];
	int nodes,i,j,k,count=0;
	printf("\nEnter the number of nodes : ");
	scanf("%d",&nodes);//Enter the nodes
	printf("\nEnter the cost matrix :\n");
	for(i=0;i<nodes;i++)
	{
		for(j=0;j<nodes;j++)
		{
			scanf("%d",&costmat[i][j]);
			costmat[i][i]=0;
			rt[i].dist[j]=costmat[i][j];//initialise the distance equal to cost matrix			
			rt[i].from[j]=j;
		}
	}
	do
	{
		count=0;
		for(i=0;i<nodes;i++)
		//We choose arbitary vertex k and we calculate the direct distance from the node i to k using the cost matrix
		//and add the distance from k to node j
		for(j=0;j<nodes;j++)
		    for(k=0;k<nodes;k++)
			if(rt[i].dist[j]>costmat[i][k]+rt[k].dist[j])
			{//We calculate the minimum distance
				rt[i].dist[j]=rt[i].dist[k]+rt[k].dist[j];
				rt[i].from[j]=k;
				count++;
			}
	}while(count!=0);
	for(i=0;i<nodes;i+=2)
	{
		printf("\n");
		for(k=i;k<i+2&&k<nodes;k++)printf("Routing Table of router %d\t\t",k+1);
		printf("\n");	
		for(k=i;k<i+2&&k<nodes;k++)printf(" ------------------------------\t\t");
		printf("\n");		
		for(k=i;k<i+2&&k<nodes;k++)printf("| Destination | Via | Distance |\t");
		printf("\n");
		for(k=i;k<i+2&&k<nodes;k++)printf(" ------------------------------\t\t");
		printf("\n");
				
		for(j=0;j<nodes;j++)
		{
			for(k=i;k<i+2&&k<nodes;k++)	
			printf("|\t%-6d|  %-2d |    %-6d|\t",j+1,rt[k].from[j]+1,rt[k].dist[j]);
			printf("\n");
			for(k=i;k<i+2&&k<nodes;k++)printf(" ------------------------------\t\t");
			printf("\n");
		}
	}
	printf("\n\n");
	return 0;
}
