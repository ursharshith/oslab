#include<stdio.h>

int main()
{
	int n;
	printf("enter number of proceses :");
	scanf("%d",&n);
	int m;
	printf("enter number of blocks :");
	scanf("%d",&m);
	int p[n],b[m];
	int visit[m];
	int PC[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&p[i]);
		PC[i]=0;
	}
	for(int i=0;i<m;i++)
	{
		scanf("%d",&b[i]);
		visit[i]=0;
	}
	printf("\n");
	int IF=0,EF=0;
	for(int j=0;j<n;j++){
		for(int i=0;i<m;i++)
		{
			if(visit[i]!=1 && p[j]<=b[i])
			{
				visit[i]=1;
				PC[j]=1;
				IF=IF+b[i]-p[j];
				printf("P.%d-->BLOCK.%d\n",(j+1),(i+1));
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
		if(PC[i]!=1)
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
	
	printf("Internal fragmentation is :%d\n",IF);
	
	printf("External fragmentation is :%d\n",EF);
	
}

