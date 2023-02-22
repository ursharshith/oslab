#include <stdio.h>
#include <stdlib.h>

int main(){
	int n;
	printf("Enter no of requests: ");
	scanf("%d",&n);
	int req[n];
	for(int i=0;i< n;i++){
		scanf("%d",&req[i]);
	}
	int a,c;
	printf("enter read write arm: ");
	scanf("%d",&a);
	printf("enter no of cylinders: ");
	scanf("%d",&c);
	int heads=0;
	heads += abs(a-req[0]);
	for(int i=1;i< n;i++){
		heads += abs(req[i]-req[i-1]);
	}
	printf("no of head movements: %d\n",heads);
}
