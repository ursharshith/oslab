#include<stdio.h>

int main()
{
	int n,m;
	printf("enter no of proceses :");
	scanf("%d",&n);
	printf("enter no of blocks :");
	scanf("%d",&m);
	int p[n];
	int b[m];
	int blocks[m];
	int visit[m];
	int pc[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&p[i]);
		pc[i]=0;
	}
	for(int i=0;i<m;i++)
	{
		scanf("%d",&b[i]);
		visit[i]=0;
		blocks[i]=i+1;
	}
	for(int i=0;i<m-1;i++)
	{
		for(int j=0;j<m-i-1;j++)
		{
			if(b[j]<b[j+1])
			{
				int temp=b[j];
				b[j]=b[j+1];
				b[j+1]=temp;
				temp=blocks[j];
				blocks[j]=blocks[j+1];
				blocks[j+1]=temp;
			}
		}
	}
	printf("\n");
	int IF=0,EF=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(visit[j]!=1 && p[i]<=b[j])
			{
				IF=IF+b[j]-p[i];
				visit[j]=1;
				pc[i]=1;
				printf("P.%d-->Block.%d\n",(i+1),blocks[j]);
				break;
			}
		}
	}
	printf("\n");
	
	int memory=0;
	for(int i=0;i<m;i++) 
	{ 
		if(visit[i]!=1)
		{
			memory=memory+b[i];
		}
	}
	for(int i=0;i<n;i++)
	{
		if(pc[i]!=1)
		{
			printf("P.%d must wait\n",(i+1));
			if(p[i]<=memory)
			{
				EF=EF+memory;
				break;
			}
		}
	}
	printf("\n");
	printf("Internal fragmantation :%d\n",IF);
	printf("External fragmantation :%d",EF);
	
}
