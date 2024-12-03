#include<stdio.h>
int main(){
	int arr[9]={1,4,3,2,5,9,7,8,6};
	int m = sizeof(arr)/sizeof(arr[0]);
	printf("mang truoc khi sap xep la :\n");
	for(int i=0;i<m;i++){
	printf("%d\n",arr[i]);
    }
	int end = sizeof(arr)/sizeof(int);
	int n=5;
	int mid;
	int start=0;
	for(int i=0;i<m-1;i++){
		for(int j=0;j<m-i-1;j++){
			if(arr[j]<arr[j+1]){
				int temp = arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	printf("mang sau khi sap xep la :\n");
	for(int i=0;i<m;i++){
		printf("%d\n",arr[i]);
	}
	while(start<=end) {
		mid = (start+end)/2;
		if(arr[mid]==n){
			printf("vi tri phan tu can tim tai vi tri %d \n", mid);
			return 0;
		} else if (arr[mid]>n){
			end = mid-1;
		} else{
			start =mid+1;
		}
	}
	printf("khong tim thay phan tu can tim");
	return 0;
}
