#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Books {
    char id[10], fullName[100], author[100], type[50];
    float price;
};
void addBooks(struct Books b[], int *sizePtr) {
    for (int i = 0; i < *sizePtr; i++) {
        getchar();
        printf("\nNhap thong tin sach thu %d\n", i + 1);
        printf("Nhap ID: ");
        fgets(b[i].id, 10, stdin);
        b[i].id[strcspn(b[i].id, "\n")] = '\0';
        printf("Nhap ten: ");
        fgets(b[i].fullName, 100, stdin);
        b[i].fullName[strcspn(b[i].fullName, "\n")] = '\0';
        printf("Nhap ten tac gia: ");
        fgets(b[i].author, 100, stdin);
        b[i].author[strcspn(b[i].author, "\n")] = '\0';
        printf("Nhap the loai: ");
        fgets(b[i].type, 50, stdin);
        b[i].type[strcspn(b[i].type, "\n")] = '\0';
        printf("Nhap gia tien: ");
        scanf("%f", &b[i].price);
    }
    printf("\n");
}
void saveToFile(struct Books b[], int size) {
    FILE *file = fopen("bt09.bin", "wb");
    if(file == NULL){
    	printf("\nKhong the mo file\n\n");
	}
    fwrite(b, sizeof(struct Books), size, file);
    fclose(file);
    printf("\nLuu hoan tat\n\n");
}
void getToFile(struct Books b[], int *sizePtr) {
    FILE *file = fopen("bt09.bin", "rb");
    if(file == NULL){
    	printf("\nKhong the mo file\n\n");
		return;	
	}
    *sizePtr = 0;
    while (fread(&b[*sizePtr], sizeof(struct Books), 1, file)){
        (*sizePtr)++;
    }
    fclose(file);
    printf("\nDoc thong tin tu file thanh cong\n\n");
}
void displayBooks(struct Books b[], int size) {
    if (size == 0) {
        printf("\nDanh sach trong\n\n");
        return;
    }
    for (int i = 0; i < size; i++) {
        printf("\nThong tin sach thu %d:\n", i + 1);
        printf("ID: %s\n", b[i].id);
        printf("Ten: %s\n", b[i].fullName);
        printf("Tac gia: %s\n", b[i].author);
        printf("The loai: %s\n", b[i].type);
        printf("Gia: %.2f\n", b[i].price);
    }
    printf("\n");
}
int main() {
    struct Books b[100];
    int size = 0, choice;
    int *sizePtr = &size;
    do {
        printf("1. Nhap so luong va thong tin sach\n");
        printf("2. Luu thong tin sach vao file\n");
        printf("3. Lay thong tin sach tu file\n");
        printf("4. Hien thi thong tin sach\n");
        printf("5. Thoat\n");
        printf("Nhap chuc nang: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nNhap so luong sach (toi da 100): ");
                scanf("%d", sizePtr);
                if (*sizePtr <= 0 || *sizePtr > 100) {
                    printf("\nNhap khong hop le\n\n");
                } else {
                    addBooks(b, sizePtr);
                }
                break;
            case 2:
                saveToFile(b, size);
                break;
            case 3:
                getToFile(b, sizePtr);
                break;
            case 4:
                displayBooks(b, size);
                break;
            case 5:
                printf("\nThoat chuong trinh.\n");
                break;
            default:
                printf("\nChuc nang khong hop le\n\n");
                break;
        }
    } 
	while (choice != 5);
    return 0;
}

