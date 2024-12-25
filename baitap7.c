#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Students{
	char id[10];
	char fullName[100];
	int age;
};
void addStudents(struct Students *s, int size, FILE *file){
	for(int i = 0; i < size; i++){
		fflush(stdin);
		printf("\nNhap ID: ");
		fgets(s[i].id, 10, stdin);
		s[i].id[strlen(s[i].id) - 1] = '\0';
		fprintf(file, "ID: %s\t", s[i].id);
		printf("Nhap ten sinh vien: ");
		fgets(s[i].fullName, 100, stdin);
		s[i].fullName[strlen(s[i].fullName) - 1] = '\0';
		fprintf(file, "Ten sinh vien: %s\t", s[i].fullName);
		printf("Nhap tuoi: ");
		scanf("%d", &s[i].age);
		fprintf(file, "Tuoi: %d\n", s[i].age);
	}
}
int main(){
	struct Students *s;
	int size;
	printf("Nhap so luong sinh vien: ");
	scanf("%d", &size);
	s = (struct Students *)calloc(size, sizeof(struct Students));
	FILE *file;
	file = fopen("students.txt", "w");
	addStudents(s, size, file);
	printf("Them hoan tat");
	fclose(file);
	free(s);
	return 0;
}

