#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void main()
{
	int p,f,i,j;
	int pf=0;
	printf("Enter no.of pages: ");
	scanf("%d",&p);
	int Pages[p];
	printf("Enter Page numbers: ");
	for(i=0;i<p;i++)
		scanf("%d",&Pages[i]);
	printf("Enter no.of frames: ");
	scanf("%d",&f);
	int Frames[f],Priority[f];
	int M[f][p];
	for(i=0;i<f;i++)
		Frames[i]=-1;
	int temp=f-1;
	for(i=0;i<f;i++)
	{
		Frames[i]=Pages[i];
		Priority[i]=temp--;
		pf++;
		for(j=0;j<f;j++)
		{
			M[j][i]=Frames[j];
		}
	}
	for(i=f;i<p;i++)
	{
		int flag=0;
		for(j=0;j<f;j++)
		{
			if(Frames[j]==Pages[i])
			{
				flag=1;
				for(j=0;j<f;j++)
					Priority[j]=Priority[j]-1;
				Priority[j]=0;
				break;
			}
		}
		if(flag==0)
		{
			pf++;
			int min=Priority[0],index=0;
			for(j=0;j<f;j++)
			{
				if(min>Priority[j])
				{
					min=Priority[j];
					index=j;
				}
			}
			for(j=0;j<f;j++)
			{
				Priority[j]=Priority[j]-1;
			}
			Frames[index]=Pages[i];
			Priority[index]=0;
		}
		for(j=0;j<f;j++)
				M[j][i]=Frames[j];
	}
	printf("\nMOST REPLACEMENT ALGORITHM");
	for(i=0;i<f;i++)
	{
		printf("\n");
		for(j=0;j<p;j++)
		{
			if(M[i][j]!=-1)
				printf("  %d  ",M[i][j]);
			else
				printf("     ");
		} 
	}
	printf("\nNo.of Page Faults: %d ",pf);
	printf("\nNo.of Page Replacements: %d ",pf-f);
}
