#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
	char str[100];
	FILE *file;
	printf("Nhap chuoi: ");
	fgets(str, sizeof(str), stdin);
	str[strlen(str) - 1] = '\0';
	file = fopen("bt01.txt", "w");
	fprintf(file, "%s", str);
	printf("\nThem hoan tat\n");
	fclose(file);
	return 0;
}

