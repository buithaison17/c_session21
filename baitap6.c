#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
	char str[100];
	FILE *f1, *f2;
	f1 = fopen("bt01.txt", "r");
	f2= fopen("bt06.txt", "w");
    while(fgets(str, sizeof(str), f1) != NULL){
        fprintf(f2, "%s", str);
    }
    printf("Them hoan tat\n");
    fclose(f1);
    fclose(f2);
	return 0;
}

