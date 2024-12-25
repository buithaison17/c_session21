#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Students{
    char id[10], fullName[100];
    int age;
};
void getStudents(struct Students s[100], FILE *file, int *index){
	while(fscanf(file, "ID: %[^\t]\tTen sinh vien: %[^\t]\tTuoi: %d\n", 
				s[*index].id,
				s[*index].fullName,
				&s[*index].age) != EOF){
		(*index)++;
		if(*index >= 100){
			printf("\nVuot qua so luong sinh vien\n");
			break;
		}
	}
}
void printStudents(struct Students s[], int index){
	printf("\nThong tin sinh vien\n");
	printf("--------------------\n");
	for(int i = 0; i < index; i++){
		printf("ID: %s", s[i].id);
		printf("\nTen sinh vien: %s", s[i].fullName);
		printf("\nTuoi: %d", s[i].age);
		printf("\n--------------------\n");
	}
}
int main(){
	struct Students s[100];
	FILE *file = fopen("students.txt", "r");
	int index = 0;
	getStudents(s, file, &index);
	printStudents(s, index);
	return 0;
}


