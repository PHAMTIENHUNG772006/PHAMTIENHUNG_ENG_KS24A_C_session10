#include <stdio.h>
int main(){
	int row, col;
	printf("Nhap so hang cho mang: ");
	scanf("%d", &row);
	printf("Nhap so cot cho mang: ");
	scanf("%d", &col);
	
	if ( row < 1 || col < 1){
		printf("\n du lieu khong hop le hay nhap so duong !");
		return 1;
	}
	
	int arr[row][col] ;
	
	for ( int i = 0 ; i < row ; i++){
		for ( int j = 0 ; j < col ; j++){
			printf(" Nhap phan tu thu %d cua hang %d: ",j+1, i+1);
			scanf("%d", &arr[i][j]);
		}
		printf("\n");
	}
	
	printf("\n Mang ban dau: \n" );
	for ( int i = 0 ; i < row ; i++){
		for ( int j = 0 ; j < col ; j++){
			printf("\t%d ", arr[i][j]);
		}
		printf("\n");
	}
	
	printf("\n Mang da sap xep: \n" );
	for ( int i = 0 ; i < col ; i++){
		for ( int j =0; j< row; j++){
			for ( int k = 0 ; k < row-1-j ; k++){
				if ( arr[k][i] > arr[k+1][i]){
					int temp = arr[k][i];
					arr[k][i] = arr[k+1][i];
					arr[k+1][i] = temp;
				}
			}
		} 
	}
	for ( int i = 0 ; i < row ; i++){
		for ( int j = 0 ; j < col ; j++){
			printf("\t%d ", arr[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
