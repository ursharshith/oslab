#include <stdio.h>
#include <stdlib.h>

int main(){
	int n;
	printf("Enter no of requests: ");
	scanf("%d",&n);
	int req[n];
	int vis[n];
	for(int i=0;i< n;i++){
		scanf("%d",&req[i]);
		vis[n]=-1;
	}
	//sorting 
	
	for(int i=0;i< n;i++){
		for(int j=i+1;j<n;j++){
			if(req[i] > req[j]){
				int temp = req[i];
				req[i] = req[j];
				req[j] = temp;
			}
		}
	}
	int a,c;
	printf("enter read write arm: ");
	scanf("%d",&a);
	printf("enter no of cylinders: ");
	scanf("%d",&c);
	int k;
	for(k=0;k< n;k++){
		if(req[k] == a){
			break;
		}
	}
	int i = k-1;
	int j = k+1;
	int heads = 0;
	while(i >= 0 && j < n){
		if(abs(req[i]-a) < abs(req[j]-a)){
			printf("%d --> %d , ",a,req[i]);
			heads += abs(a-req[i]);
			a = req[i];
			vis[i]=1;
			i--;
		}
		else{
			printf("%d --> %d , ",a,req[j]);
			heads += abs(a-req[j]);
			a = req[j];
			vis[j]=1;
			j++;
		}
	}
	if(i < 0){
		while(j < n){
			printf("%d --> %d , ",a,req[j]);
			heads += abs(a-req[j]);
			a = req[j];
			j++;
		}
	}
	if(j >= n){
		while(i >= 0){
			printf("%d --> %d , ",a,req[i]);
			heads += abs(a-req[i]);
			a = req[i];
			i--;
		}
	}
	printf("no of head movements: %d\n",heads);
	
	

}
