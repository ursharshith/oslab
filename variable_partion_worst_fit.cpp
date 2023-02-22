#include<stdio.h>

int swap(int a[],int i,int j)
{
	int temp=a[i];
	a[i]=a[j];
	a[j]=temp;
}

int sort(int a[],int b[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(a[j]<a[j+1])
			{
				swap(a,j,j+1);
				swap(b,j,j+1);
			}
		}
	}
}

int main()
{
	int n;
	printf("enter number of proceses :");
	scanf("%d",&n);
	int p[n];
	int visit_p[n];
	int m;
	printf("enter number of blocks :");
	scanf("%d",&m);
	int b[m];
	int block[m];
	int visit_b[m];
	
	for(int i=0;i<n;i++)
	{
		scanf("%d",&p[i]);
		visit_p[i]=0;
	}
	for(int i=0;i<m;i++)
	{
		scanf("%d",&b[i]);
		block[i]=i+1;
		visit_b[i]=0;
	}
	
	sort(b,block,m);
	
	int sum=0,ef=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(p[i]<=b[j])
			{
				printf("P%d---->block%d\n",i+1,block[j]);
				b[j]=b[j]-p[i];
				visit_p[i]=1;
				visit_b[j]=1;
				break;
			}
		}
	}
	
	for(int i=0;i<m;i++)
	{
		if(visit_b[i]==0)
		{
			sum+=b[i];
		}
	}
	
	for(int i=0;i<n;i++)
	{
		if(visit_p[i]==0)
		{
			printf("....P%d must wait....",i+1);
			if(sum>=p[i])
			{
				ef=sum;
			}
		}
	}
	
	printf("\nexternal fragmentation is :%d",ef);
}
