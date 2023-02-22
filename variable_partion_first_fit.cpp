#include<stdio.h>

int main()
{
	int n;
	printf("enter the proceses :");
	scanf("%d",&n);
	int p[n];
	int visit_p[n];
	int m;
	printf("enter the blocks :");
	scanf("%d",&m);
	int b[m];
	int visit[m];
	printf("enter the proceses memory :");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&p[i]);
		visit_p[i]=0;
	}
	printf("enter the blocks memory :");
	for(int i=0;i<m;i++)
	{
		scanf("%d",&b[i]);
		visit[i]=0;
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(p[i]<=b[j])
			{
				printf("p%d-->block%d\n",i+1,j+1);
				b[j]=b[j]-p[i];
				visit[j]=1;
				visit_p[i]=1;
				break;
			}
		}
	}
	int sum=0;
	for(int i=0;i<m;i++)
	{
		if(visit[i]==0)
		{
			sum+=b[i];
		}
	}
	int ef=0;
	for(int i=0;i<n;i++)
	{
		if(visit_p[i]!=1)
		{
			printf("P%d must wait",(i+1));
			if(sum>=p[i])
			{
				ef=sum;
			}
		}
	}
	printf("External fragmentation is :%d",ef);
}
