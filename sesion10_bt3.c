#include<stdio.h>
int main(){
	int arr[]={1,5,2,7,3,6};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	for(int i=1;i<n;i++){
	int key = arr[i];
	int j = i - 1;
	
	while(j >= 0 && arr[j] > key){
		arr[j+1]=arr[j];
		j = j - 1;
	}
	arr[j+1] = key;
    }
    printf("cac phan tu trong mang \n");
    for(int i=0;i<n;i++){
    printf("%d\n", arr[i]);
	}
	printf("\n");
    return 0;
}
