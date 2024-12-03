#include<stdio.h>
int main(){
	
	int arr[]={2,6,7,5,9,3};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	for( int i = 0; i < n-1;i++){
	   int min = i;
        for(int j=i+1;j<n;j++){
	      	if(arr[j]<arr[min]){
			min = j;
			}	
		}
		int temp = arr[min];
		arr[min]= arr[i];
		arr[i]= temp;
		}
		printf("mang cua ban sau khi sap xep la : \n");
		for(int i=0;i<n;i++){
		printf("%d \n", arr[i]);	
		}
		printf("\n");
		
		return 0;
	}
