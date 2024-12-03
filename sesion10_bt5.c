#include<stdio.h>
int main(){
	int arr[]={1,4,3,2,5,9,7,8,6};
	int m = sizeof(arr)/sizeof(arr[0]);
	int mid, n;
	int end = m -1;
	int start=0;
	
	printf("mang truoc khi sap xep la :\n");
	for(int i=0;i<m;i++){
	printf("%d\n",arr[i]);
	}
	
	for(int i=0;i<m-1;i++){
		for(int j = 0 ;j < m - i - 1;j++){
			if(arr[j] < arr[j+1]){
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
	 printf("moi ban nhap gia tri can tim kiem : ");
    scanf("%d", &n);
	while(start <= end) {
		mid = (start + end) / 2;
		if(arr[mid] > n){
	       start = mid +1;
		} else if (arr[mid] < n){
			end = mid - 1;
		} else{
		   printf("phan tu %d co vi tri la %d", n, mid+1);
		   break;
		}
	}
		if(start>end){
			printf("phan tu %d  khong xuat hien trong mang",n);
	}
	return 0;
}
