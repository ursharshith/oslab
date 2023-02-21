
// #include<stdlib.h>
// #include<stdio.h>
// int main()
// {
//     int RQ[100],i,n,TotalHeadMoment=0,initial;
//     printf("Enter the number of Requests\n");
//     scanf("%d",&n);
//     printf("Enter the Requests sequence\n");
//     for(i=0;i<n;i++)
//      scanf("%d",&RQ[i]);
//     printf("Enter initial head position\n");
//     scanf("%d",&initial);

//     // logic for FCFS disk scheduling
    
//     for(i=0;i<n;i++)
//     {
//         TotalHeadMoment=TotalHeadMoment+abs(RQ[i]-initial);
//         initial=RQ[i];
//     }
    
//     printf("Total head moment is %d",TotalHeadMoment);
//     return 0;
// }

#include <stdio.h>
#include <math.h>

int size = 8;

void FCFS(int arr[],int head)
{
	int seek_count = 0;
	int cur_track, distance;

	for(int i=0;i<size;i++)
	{
		cur_track = arr[i];
		distance = fabs(head - cur_track);
		seek_count += distance;
		head = cur_track;
	}

	printf("Total number of seek operations: %d\n",seek_count);
    printf("Seek Sequence is\n");

	for (int i = 0; i < size; i++) {
		printf("%d\n",arr[i]);
	}
}

int main()
{
	int n,head;
    printf("Enter the number of Requests\n");
    scanf("%d",&n);
    int arr[n+1];
    printf("Enter the Requests sequence\n");
    for(int i=0;i<n;i++)
     scanf("%d",&arr[i]);
    printf("Enter initial head position\n");
    scanf("%d",&head);
	
	FCFS(arr,head);

	return 0;
}
