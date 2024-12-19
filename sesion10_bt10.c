#include <stdio.h>
int main(){
	int n;
	printf("Nhap so hang va cot cho mang: ");
	scanf("%d", &n);
	
	if ( n < 1 ){
		printf("\ndu lieu khong hop le hay nhap so duong !");
		return 1;
	}
	
	int arr[n][n] ;
	
	for ( int i = 0 ; i < n ; i++){
		for ( int j = 0 ; j < n ; j++){
			printf(" Nhap phan tu thu %d cua hang %d: ",j+1, i+1);
			scanf("%d", &arr[i][j]);
		}
		printf("\n");
	}
	
	printf("\nket qua nhap: \n");
	for ( int i = 0 ; i < n ; i++){
		for ( int j = 0 ; j < n ; j++){
			printf ( "\t%d", arr[i][j] );
		}
		printf("\n");
	}
	printf("\nduong cheo phu ban dau: \n");
	for( int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if ( j + i == 2 ){
				printf ( "\t%d", arr[i][j] );
			} else{
				printf("\t");
			}
		}
		printf("\n");
	}
	int diag[n];
    int k = 0;
    for (int i = 0; i < n; i++) {
        diag[k++] = arr[i][n - i - 1];
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (diag[i] > diag[j]) {
                int temp = diag[i];
                diag[i] = diag[j];
                diag[j] = temp;
            }
        }
    }
    k = 0;
    for (int i = 0; i < n; i++) {
        arr[i][n - i - 1] = diag[k++];
    }
    printf("\nDuong cheo phu da sap xep: \n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j + i == n - 1) { 
                printf("\t%d", arr[i][j]);
            } else {
                printf("\t");
            }
        }
        printf("\n");
    }
    return 0;
}
