#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_CATEGORY 10
#define MAX_ID_LENGTH 20
#define MAX_NAME_LENGTH 50
struct Category{
	char CategoryId[MAX_ID_LENGTH];
	char CategoryName[MAX_NAME_LENGTH];
};
struct Product{
	char productId[10];
	char cateGory[10];
	char productName[30];
	int quantity;
	int price;
};
struct Product products[100];
struct Category category[MAX_CATEGORY];
int numberProduct = 0;
int numberCategory = 0;
void menuAdmin();
void menuCategory();
void menuProduct();
void loadCategoryFromFile();
void saveCategoryToFile();
void saveProductToFile();
void loadProductFromFile();
void printCategory();
void addCategory();
void editCategory();
void deletCategory();
void searchCategory();
void arrangeCategory();
void addProduct();
void printProduct();
void editProduct();
void deletProduct();
void searchProduct();
void arrangeProduct();
void menuFilterByCategory();
int main () {
	loadCategoryFromFile();
	loadProductFromFile();
	struct Product products[100];
	int choice;
	do{
		printf("***Store Management System Using C***\n");
		printf("\n");
		printf("SELECT A FUNCTION\n");
		printf("=====================\n");
		printf("[1]. Admin\n");
		printf("[2]. Customer\n");
		printf("[0]. Exit the program\n");
		printf("=====================\n");
		printf("Enter the choice: ");
		scanf("%d", &choice);
		switch(choice){
			case 0:
				printf("Da thoat chuong trinh thanh cong");
				break;
			case 1:
				menuAdmin();
				break;
			case 2:
				printf("Chuc nang chua thuc hien..!\n");
				break;
		}
	}while(choice != 0);
	saveCategoryToFile();
	saveProductToFile();
	return 0;
}

void menuAdmin(){
	int choice;
	do{
		printf("ADMIN MENU\n");
		printf("===========================\n");
		printf("[1]. Quan li danh muc\n");
		printf("[2]. Quan li san pham\n");
		printf("[0]. Thoat Khoi Chuong Tinh\n");
		printf("===========================\n");
		printf("Nhap lua chon cua ban: ");
		scanf("%d", &choice);
		switch (choice){
			case 0:
				printf("Quay lai menu chinh\n");
				break;
			case 1:
				menuCategory();			
				break;
			case 2:
				menuProduct();
				break;
			default:
				printf("Lua chon khong hop le!\n");
		}
	}while (choice != 0);
}

void printCategory() {
	 if (numberCategory <= 0) {
        printf("Danh sach danh muc rong..!\n");
        return;
    }
    printf("\tDanh sach danh muc:\n");
    printf("\t=========================================\n");
    printf("\t| Ma danh muc       | Ten danh muc      |\n");
    printf("\t|-------------------|-------------------|\n");
    for (int i = 0; i < 10; i++) {
        if (strlen(category[i].CategoryId) > 0) {
            printf("\t|%-19s|%-19s|\n",
			category[i].CategoryId, 
			category[i].CategoryName);
            printf("\t|-------------------|-------------------|\n");
        }
    }
}
void addCategory() {
    if (numberCategory >= MAX_CATEGORY) {
        printf("Danh sach danh muc da day\nNeu muon them vui long xoa phan tu trong danh muc khong can thiet\n");
        return;
    }
    for (int i = 0; i < 10; i++) {
        if (strlen(category[i].CategoryId) == 0) {
            printf("Them danh muc moi:\n");
            int validId = 0;
            do {
                printf("ID danh muc (max 10 ky tu): ");
                fgets(category[i].CategoryId, sizeof(category[i].CategoryId), stdin);
                category[i].CategoryId[strcspn(category[i].CategoryId, "\n")] = '\0';
                if (strlen(category[i].CategoryId) == 0) {
                    printf("ID danh muc ban nhap rong..!\n");
                    continue; 
                }
                if (strlen(category[i].CategoryId) > 10) {
                	printf("ID danh muc qua dai, vui long nhap lai (max 10 ky tu).\n");
                } else {
                int idExist = 0;
                    for (int j = 0; j < i; j++) {
                        if (strcmp(category[i].CategoryId, category[j].CategoryId) == 0) {
                            printf("ID danh muc da ton tai!\n");
                            idExist = 1;
                            break;
                        }
                    }
                    if (idExist == 0) {
                    validId = 1;  
                    }
                }
            } while (!validId);
            int validName = 0;
            do {
                printf("Ten danh muc (max 20 ky tu): ");
                fgets(category[i].CategoryName, sizeof(category[i].CategoryName), stdin);
                category[i].CategoryName[strcspn(category[i].CategoryName, "\n")] = '\0';
                if (strlen(category[i].CategoryName) == 0) {
                    printf("Thong tin danh muc ban nhap rong..!\n");
                    continue; 
                }
                if (strlen(category[i].CategoryName) > 20) {
                    printf("Ten danh muc qua dai, vui long nhap lai (max 20 ky tu).\n");
                } else {
                    int nameExist = 0;
                    for (int j = 0; j < i; j++) {
                        if (strcmp(category[i].CategoryName, category[j].CategoryName) == 0) {
                            printf("Ten danh muc da ton tai!\n");
                            nameExist = 1;
                            break;
                        }
                    }
                    if (nameExist == 0) {
                        validName = 1; 
                    }
                }
            } while (!validName);
            printf("Them danh muc thanh cong!\n");
            numberCategory++;
            return;
        }
    }
    printf("\nDanh sach danh muc da day, khong the them moi!\n");
}
void loadCategoryFromFile() {
    FILE *file = fopen("category.txt", "r");
    if (file == NULL) {
        printf("\nLoi Khong the mo file!\n");
        return;
    }
    int index = 0;
    while (fscanf(file, "%[^,],%[^\n]\n", category[index].CategoryId, category[index].CategoryName) == 2) {
        index++;
        if (index >= 10) break;
    }
    fclose(file);
    printf("\nDanh muc da duoc tai len file.\n");
}
void saveCategoryToFile() {
    FILE *file = fopen("category.txt", "w");
    if (file == NULL) {
        printf("\nLoi khong the mo file !\n");
        return;
    }
    for (int i = 0; i < 10; i++) {
        if (strlen(category[i].CategoryId) > 0) {
            fprintf(file, "%s, %s\n", category[i].CategoryId, category[i].CategoryName);
        }
    }
    fclose(file);
}
void editCategory() {
    char idedit[30];
    int found = 0;
    printf("Nhap ID danh muc can sua: ");
    while (getchar() != '\n');
    fgets(idedit, sizeof(idedit), stdin);
    idedit[strcspn(idedit, "\n")] = '\0';
    for (int i = 0; i < 10; i++) {
        if (strcmp(idedit, category[i].CategoryId) == 0) {
            found = 1;
            printf("\nThong tin danh muc hien tai:\n");
            printf("\nID: %s\n", category[i].CategoryId);
            printf("\nTen: %s\n", category[i].CategoryName);
            printf("\nNhap thong tin sua doi:\n");
            printf("\nID danh muc moi: ");
            printf("\nTen danh muc moi: ");
            fgets(category[i].CategoryName, sizeof(category[i].CategoryName), stdin);
            category[i].CategoryName[strcspn(category[i].CategoryName, "\n")] = '\0';
            printf("\nThong tin danh muc duoc sua thanh cong!\n");
            break;
        }
    }
    if (!found) {
        printf("\nKhong tim thay ID danh muc!\n");
    } else {
        saveCategoryToFile();
    }
}
void deleteCategory(){
	char idDelet[30];
	int found = 0;
	char a[30];
	printf("Hay nhap ID danh muc muon xoa: ");
	while(getchar() != '\n');
	fgets(idDelet, sizeof(idDelet),stdin);
	idDelet[strcspn(idDelet, "\n")] = '\0';
	for (int i = 0; i < 10; i++) {
        if (strcmp(idDelet, category[i].CategoryId) == 0) {
            found = 1;
            break;
        }
    }
    if(!found) {
    	printf("\nKhong tim thay ID\n");
    	return;
	}
	printf("\nBan co chac chan muon xoa (yes/no): ");
	fgets(a, sizeof(a),stdin);
	a[strcspn(a, "\n")] = '\0';
	if(strcmp(a, "yes") == 0){
		for (int i = 0; i < 10; i++) {
        if (strcmp(idDelet, category[i].CategoryId) == 0) {
            found = 1;
            for(int j = i; j < 10; j++){
            	category[j] = category[j + 1];
			}
		strcpy(category[9].CategoryId, "");
        strcpy(category[9].CategoryName, "");
        numberCategory--;
        printf("\nDa xoa danh muc thanh cong!\n");
        break;
        }
    }
    printCategory();
  }
  else{
  	printf("Huy thao tac xoa\n");
  }
}

void toupperCase(char *category) {
    for (int i = 0; category[i]; i++) {
        category[i] = toupper((unsigned char)category[i]);  
    }
}
void searchCategory() {
    char a[30];
    int found = 0;
    printf("Moi ban nhap ten danh muc muon tim: ");
    while(getchar() != '\n');  
    fgets(a, sizeof(a), stdin);
    a[strcspn(a, "\n")] = '\0';  
    toupperCase(a);  
    for (int i = 0; i < 10; i++) {
        char temp[30];
        strcpy(temp, category[i].CategoryName);
        toupperCase(temp);
        if (strstr(temp, a) != NULL) {
            found = 1;
            printf("\tDa tim thay thong tin..!\n");
            printf("\t|-------------------|----------------|\n");
            printf("\t| Ma danh muc       |  Ten danh muc  |\n"); 
            printf("\t|-------------------|----------------|\n");
            printf("\t| %-13s     |    %-12s|\n", category[i].CategoryId, category[i].CategoryName);
            printf("\t|-------------------|----------------|\n");
            break; 
        }
    }
    if (!found) {
        printf("Khong tim thay san pham can tim!\n");
    }
}
void arrangeCategory() {
    int choice;
    do{
    printf("Hay chon cach sap xep :\n");
    printf("1. Sap xep tang\n");
    printf("2. Sap xep giam\n");
    printf("0. Quay lai\n");
    printf("Nhap lua chon: ");
    scanf("%d", &choice);
    getchar();
    switch(choice){
    	case 1:
    		for (int i = 0; i < 10; i++) {
            	for (int j = i + 1; j < 10; j++) {
                	if (strcmp(category[i].CategoryName, category[j].CategoryName) > 0) {
                    	struct Category temp = category[i];
                    	category[i] = category[j];
                    	category[j] = temp;
               			}
            		}
       	 		}	 
       		printf("\nDanh muc da duoc sap xep tang theo ten.\n");
       		printf("danh muc sau khi sap xep la : \n");
       		printCategory();
    		break;
    		case 2:
    		for (int i = 0; i < 10; i++) {
            	for (int j = i + 1; j < 10; j++) {
                	if (strcmp(category[i].CategoryName, category[j].CategoryName) < 0) {
                    	struct Category temp = category[i];
                    	category[i] = category[j];
                    	category[j] = temp;
                		}
            		}
        		}
        		printf("\nDanh muc da duoc sap xep giam theo ten.\n");
        		printf("danh muc sau khi sap xep la : \n");
       		    printCategory();
    			break;
    		case 0:
    			printf("Da thoat sap xep..!\n");
    			break;
    		default:
    		printf("Lua chon khong hop le. Vui long thu lai.\n");	
			}
		}while(choice != 0);
        return;
} 
void menuCategory() {
    int choice;
    loadCategoryFromFile();
    do {
        printf("*****QUAN LY DANH MUC*****\n");
        printf("===========================\n");
        printf("[1]. Hien thi danh sach danh muc\n");
        printf("[2]. Them danh muc moi\n");
        printf("[3]. Chinh sua danh muc\n");
        printf("[4]. Xoa danh muc\n");
        printf("[5]. Tim kiem danh muc\n");
        printf("[6]. Xap sep danh muc\n");
        printf("[0]. Quay lai menu chinh\n");
        printf("===========================\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);
        printf("\n");
        switch (choice) {
            case 0:
                printf("\nQuay lai menu chinh.\n");
                break;
            case 1:
                printCategory();
                break;
            case 2:
                addCategory();
                saveCategoryToFile();
                break;
            case 3:
            	editCategory();
            	saveCategoryToFile();
            	break;
            case 4:
            	deleteCategory();
            	saveCategoryToFile();
            	break;
            case 5:
            	searchCategory();
            	break;
        	case 6:
        		arrangeCategory();
        		break;
            default:
                printf("\nLua chon khong hop le!\n");
        }
    } while (choice != 0);
}
void menuProduct() {
    int choice;
    do {
        printf("*****QUAN LI SAN PHAM*****\n");
		printf("===========================\n");
        printf("[1]. Hien thi thong tin san pham\n");
        printf("[2]. Nhap thong tin san pham\n");
        printf("[3]. Xoa san pham\n");
        printf("[4]. Sua thong tin san pham\n");
        printf("[5]. Tim kiem san pham\n");
        printf("[6]. Sap xep san pham theo ID\n");
        printf("[7]. Loc san pham \n");
        printf("[0]. Quay lai man hinh chinh\n");
        printf("===========================\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);
        switch (choice) {
            case 0:
                printf("\tQuay lai menu chinh.\n");
                break;
            case 1:
                printProduct();
                break;
            case 2:
                addProduct();
                break;
            case 3:
            	deletProduct();
            	break;
            case 4:
            	editProduct();
            	break;
            case 5:
            	searchProduct();
            	break;
            case 6:
            	arrangeProduct();
            	break;
            case 7:
            	menuFilterByCategory();
            	break;
            default:
                printf("\nLua chon khong hop le!\n");
        }
    } while (choice != 0);
}
void loadProductFromFile() {
    FILE *file = fopen("product.txt", "r");  
    if (file == NULL) {
        printf("\nKhong the mo file1111!\n");
        return;
    }
    numberProduct = 0;  
    while (fscanf(file, "%[^,],%[^,],%[^,],%d,%d\n", 
            products[numberProduct].productId, 
            products[numberProduct].productName, 
            products[numberProduct].cateGory, 
            &products[numberProduct].quantity, 
            &products[numberProduct].price) == 5) {
        numberProduct++;  
        if (numberProduct >= 100) {
            printf("\nDanh sach san pham da day!\n");
            break;  
        }
    }
    fclose(file);  
    printf("\nSan pham da duoc tai len tu file.\n");
}
void saveProductToFile() {
    FILE *file = fopen("product.txt", "w");
    if (file == NULL) {
        printf("\nLoi khong the mo file!\n");
        return;
    }
    for (int i = 0; i < numberProduct; i++) {
        fprintf(file,"%s,%s,%s,%d,%d\n", products[i].productId,products[i].productName, products[i].cateGory, products[i].quantity, products[i].price);
    }
    fclose(file);
    printf("San pham da duoc luu vao file.\n");
}
void addProduct() {
    if (numberProduct >= 100) {
        printf("\nDanh sach san pham da day!\n");
        return;
    }
    struct Product productNew;
    printf("Nhap Ma Danh Muc: ");
    getchar();
    fgets(productNew.cateGory, sizeof(productNew.cateGory), stdin);
    productNew.cateGory[strcspn(productNew.cateGory, "\n")] = '\0';
    int found = 0;
    for (int i = 0; i < 10; i++) {
        if (strcmp(category[i].CategoryId, productNew.cateGory) == 0) {
            found = 1;
            break;
        }
    }
    if (!found) {
        printf(" Ma danh muc khong ton tai!\n");
        return;
    }
    printf(" Nhap ma san pham: ");
    getchar();  
    fgets(productNew.productId, sizeof(productNew.productId), stdin);
    productNew.productId[strcspn(productNew.productId, "\n")] = '\0';
    for (int i = 0; i < numberProduct; i++) {
        if (strcmp(products[i].productId,productNew.productId) == 0) {
            printf("\nMa san pham da ton tai tren he thong!\n");
            return;
        }
    }
    printf("Nhap Ten SP: ");
    fgets(productNew.productName, sizeof(productNew.productName), stdin);
    productNew.productName[strcspn(productNew.productName, "\n")] = '\0';
    printf("Nhap So Luong: ");
    scanf("%d", &productNew.quantity);
    getchar();
    if (productNew.quantity <= 0) {
        printf("Loi so luong ban nhap khong hop le!\n");
        return;
    }
    printf("Nhap Gia: ");
    scanf("%d", &productNew.price);
    getchar();
    if (productNew.price <= 0) {
        printf("Loi gia ban nhap khong hop le!\n");
        return;
    }
    products[numberProduct] = productNew;
    numberProduct++;
    printf("Them san pham thanh cong!\n");
    saveProductToFile();  
}
void printProduct() {
    if (numberProduct == 0) {
        printf("Danh sach san pham rong!\n");
        return;
    }
    printf("|-----|----------|--------------------|------------|----------|----------|\n");
    printf("| STT | Ma SP    | Ten San Pham       | Danh Muc   | So Luong | Gia      |\n");
    printf("|-----|----------|--------------------|------------|----------|----------|\n");
    for (int i = 0; i < numberProduct; i++) {
        printf("| %-3d | %-8s | %-18s | %-10s | %-8d | %-8d |\n", 
            i + 1, 
            products[i].productId, 
            products[i].productName, 
            products[i].cateGory,
            products[i].quantity, 
            products[i].price);
        printf("|-----|----------|--------------------|------------|----------|----------|\n");
    }
}
void editProduct() {
	char idEdit[20];
	int found = 0;
	printf("Moi ban nhap ID san pham muon sua : ");
	getchar();
	fgets(idEdit,sizeof(idEdit),stdin);
	idEdit[strcspn(idEdit, "\n")] = 0 ;
	for(int i = 0 ;i < numberProduct;i++){
		if(strcmp(idEdit,products[i].productId) == 0){
			found = 1;
			printf("Moi ban nhap ten san pham moi : ");
			fgets(products[i].productName, sizeof(products[i].productName), stdin);
    		products[i].productName[strcspn(products[i].productName, "\n")] = '\0';
    		printf("Moi ban nhap so luong moi : ");
    		scanf("%d",products[i].quantity);
    		getchar();
    		printf("Moi ban nhap so gia moi : ");
    		scanf("%d",products[i].price);
		}
	}
	if( ! found){
		printf("Khong tim thay san pham can tim..!\n");
	}
}
void deletProduct(){
	char deleteProduct[30];
	int found = 0;
	char choose[30];
	printf("Moi ban nhap ID san pham muon xoa: ");
	getchar();
    fgets(deleteProduct, sizeof(deleteProduct), stdin);
    deleteProduct[strcspn(deleteProduct, "\n")] = '\0';
    for (int i = 0; i < numberProduct; i++) {
        if (strcmp(deleteProduct, products[i].productId) == 0) {
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Khong tim thay san pham tren cua hang...!\n");
        return;
    }
    printf("Ban co muon xoa san pham khong (yes/no): ");
    fgets(choose, sizeof(choose), stdin);
    choose[strcspn(choose, "\n")] = '\0';
    if (strcmp(choose, "yes") == 0) {
        for (int i = 0; i < numberProduct; i++) {
            if (strcmp(deleteProduct, products[i].productId) == 0) {
                for (int j = i; j < numberProduct - 1; j++) {
                    products[j] = products[j + 1];
                }
                strcpy(products[numberProduct - 1].productId, "");
                strcpy(products[numberProduct - 1].productName, "");
                numberProduct--;
                saveProductToFile();
                printf("Da xoa san pham thanh cong!\n");
                printProduct();
                break;
            }
        }
    } else {
        printf("\tHuy thao tac xoa\n");
    }
}
void toupperProduct(char *product) {
    for (int i = 0; product[i]; i++) {
        product[i] = toupper((unsigned char)product[i]);  
    }
}
void searchProduct(){
	char idSearch[50];
	int found = 0;
	printf("Moi ban nhap ten san pham muon tim : ");
	getchar();
	fgets(idSearch, sizeof(idSearch), stdin);
	idSearch[strcspn(idSearch, "\n")] = '\0';
	toupperCase(idSearch);
	for(int i = 0; i < numberProduct;i++){
		char temp[30];
		strcpy(temp,products[i].productName);
		toupperProduct(temp);
		if(strcmp(idSearch,temp) == 0){
			found = 1;
			printf("\tDa tim thay !\n");
			printf("|----------|--------------------|------------|----------|----------|\n");
    		printf("| Ma SP    | Ten San Pham       | Danh Muc   | So Luong | Gia      |\n");
   			printf("|----------|--------------------|------------|----------|----------|\n");
        	printf("| %-8s | %-18s | %-10s | %-8d | %-8d |\n", 
            products[i].productId, 
            products[i].productName, 
            products[i].cateGory,
            products[i].quantity, 
            products[i].price);
    		printf("|----------|--------------------|------------|----------|----------|\n");
			break;
          }
		}
		if(!found){
			printf("khong tim thay san pham %s ma ban can tim..!",idSearch);
		}
}
void arrangeProduct() {
    int choicesort;
    int flag;
    do {
        printf("Hay chon cach sap xep :\n");
        printf("1. Sap xep tang theo ten\n");
        printf("2. Sap xep giam theo ten\n");
        printf("0. Quay lai\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choicesort);
        getchar(); 
        switch (choicesort) {
            case 1: 
                flag = 0;
                for (int i = 0; i < numberProduct; i++) {
                    for (int j = i + 1; j < numberProduct; j++) {
                        if (products[i].price > products[j].price) {
                            struct Product temp = products[i];
                            products[i] = products[j];
                            products[j] = temp;
                            flag = 1;
                        }
                    }
                }
                if (!flag) {
                    printf("San pham chua duoc sap xep..!\n");
                    return;
                }
                printf("\nSan pham da duoc sap xep theo gia.\n");
                printProduct();
                break;
            case 2: 
                flag = 0;
                for (int i = 0; i < numberProduct; i++) {
                    for (int j = i + 1; j < numberProduct; j++) {
                        if (products[i].price < products[j].price) {
                            struct Product temp = products[i];
                            products[i] = products[j];
                            products[j] = temp;
                            flag = 1;
                        }
                    }
                }
                if (!flag) {
                    printf("San pham chua duoc sap xep..!\n");
                    return;
                }
                printf("\nSan pham da duoc sap xep theo gia.\n");
                printProduct();
                break;
            case 0:
                printf("Da thoat sap xep..!\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long thu lai.\n");
        }
    } while (choicesort != 0);
}
void menuFilterByCategory() {
    int sortchoice;
    int flag;
    do { 
        printf("[1]. Loc san pham theo danh muc\n");
        printf("[2]. Loc san pham theo gia tien \n");
        printf("[0]. Quay lai\n");
        printf("Moi ban chon chuc nang : ");
        scanf("%d", &sortchoice);
        switch (sortchoice) {
            case 0:
                printf("Da thoat loc danh muc.\n");
                break;
            case 1:
                flag = 0; 
                char filterCategory[50];
                if(numberCategory == 0){
                	printf("Khong co danh muc nao trong cua hang \n");
                	return;
				}
                printf("Nhap danh muc can loc: ");
                scanf("%s", filterCategory);  
                printf("|----------|--------------------|------------|----------|----------|\n");
                printf("| Ma SP    | Ten San Pham       | Danh Muc   | So Luong | Gia      |\n");
                printf("|----------|--------------------|------------|----------|----------|\n");
                for (int i = 0; i < numberProduct; i++) {
                    if (strcmp(products[i].cateGory, filterCategory) == 0) {
                        printf("| %-8s | %-18s | %-10s | %-8d | %-8d |\n", 
                            products[i].productId, 
                            products[i].productName, 
                            products[i].cateGory,
                            products[i].quantity, 
                            products[i].price);
                            printf("|----------|--------------------|------------|----------|----------|\n");
                        flag = 1;
                    }
                }
                if (!flag) {
                	printf("Khong co ma danh muc can tim\n ");
                    printf("Chua the kich hoat loc san pham\n");
                }
                break;
            case 2:
                flag = 0;  
                if(numberProduct == 0){
                	printf("Khong co san pham nao trong cua hang \n");
                	return;
				}
                printf("Nhap moc gia can loc : ");
                int filterRack1;
                scanf("%d", &filterRack1);
                getchar();
                printf("Nhap dinh gia can loc : ");
                int filterRack2;
                scanf("%d", &filterRack2);
                if(filterRack1 < 0 || filterRack2 > 1000000000){
                	printf("Gia san pham cua ban khong hop le. vui long nhap lai..!\n");
                	return;
				}
                printf("|----------|--------------------|------------|----------|----------|\n");
                printf("| Ma SP    | Ten San Pham       | Danh Muc   | So Luong | Gia      |\n");
                printf("|----------|--------------------|------------|----------|----------|\n");
                for (int i = 0; i < numberProduct; i++) {
                    if (products[i].price >= filterRack1 && products[i].price <= filterRack2) {
                        printf("| %-8s | %-18s | %-10s | %-8d | %-8d |\n", 
                            products[i].productId, 
                            products[i].productName, 
                            products[i].cateGory,
                            products[i].quantity, 
                            products[i].price);
                            printf("|----------|--------------------|------------|----------|----------|\n");
                        flag = 1;
                    }
                }
                if (!flag) {
                    printf("Chua the kich hoat loc san pham\n");
                }
                break;
            default:
                printf("Lua chon khong hop le. vui long nhap lai\n");
        }
    } while (sortchoice != 0);
}
