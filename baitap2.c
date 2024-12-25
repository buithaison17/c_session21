#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
	FILE *file;
	char firstChar;
	file = fopen("bt01.txt", "r");
	firstChar = fgetc(file);
	printf("Ki tu dau tien la: %c", firstChar);
	fclose(file);
	return 0;
}

