#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
	char str[100];
	printf("Nhap chuoi moi: ");
	fgets(str, 100, stdin);
	str[strlen(str) - 1] = '\0';
	FILE *file;
	file = fopen("bt01.txt", "a");
	fprintf(file, " %s", str);
	printf("\nThem hoan tat\n");
	fclose(file);
	return 0;
}

