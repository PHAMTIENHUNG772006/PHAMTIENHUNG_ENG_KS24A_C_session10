#include <stdio.h>
int main(){
	int arr[]={6,4,3,2,5,1};
	int n = sizeof(arr)/sizeof(arr[0]);
	for (int i = 0; i < n - 1 ;i++){
		for (int j = 0; j < n - i - 1 ; j++) {
			if(arr[j] > arr[ j + 1]){
			int temp = arr[j];
			arr[j] = arr[j + 1];
			arr[j + 1] = temp;
			}
		}
	}
		printf("mang sau khi sap xep la : \n");
		for(int i = 0; i < n ;i++){
		printf("%d \n", arr[i]);	
		}
	return 0;
}
