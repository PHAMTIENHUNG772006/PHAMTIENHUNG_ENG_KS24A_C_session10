#include <stdio.h>
int main(){
	int arr[6]= {1,2,3,5,6};
	int index, n ;
	printf("moi ban nhap gia tri muon kiem tra : ");
	scanf("%d", &n);
	for(int i = 0; i <= 6; i++){
		if(arr[i] == n){
			printf("gia tri %d ban can tim trong mang tai vi tri arr[%d] ",n ,arr[i]);
		} else{
			printf("trong mang khong co gia tri ban can tim");
			return 1;
		}
	}
	return 0;
}
