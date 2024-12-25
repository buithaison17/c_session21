#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
	char line[100];
	FILE *file;
	file = fopen("bt01.txt", "r");
	fgets(line, sizeof(line), file);
	printf("Dong dau tien la: %s", line);
	return 0;
}

