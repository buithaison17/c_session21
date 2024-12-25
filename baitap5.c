#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
	int line;
	char str[100];
	FILE *file;
	file = fopen("bt05.txt", "w");
	printf("Nhap so dong: ");
	scanf("%d", &line);
	fflush(stdin);
	if(line <= 0){
		printf("\nNhap khong hop le\n");
	}
	else{
		for(int i = 0; i < line; i++){
			printf("\nNhap dong thu %d: ", i+1);
			fgets(str, 100, stdin);
			fprintf(file, "%s", str);
		}
	}
	fclose(file);
	file = fopen("bt05.txt", "r");
	while(fgets(str, 100, file) != NULL){
		printf("\n%s", str);
	}
	fclose(file);
	return 0;
}

