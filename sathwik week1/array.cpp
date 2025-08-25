#include<stdio.h>

int main() {
	int roll_no;
	char name[50];
	int marks[5],total=0;
	int i;

	printf("Enter Roll no: ");
	scanf("%d", &roll_no);
	
	printf("Enter Name: ");
	scanf("%[^\n]",&name);
	
	
	for(i=0; i<5;i++){
		printf("Enter Marks for subject %d: ",i+1);
		scanf("%d",&marks[i]);
		total += marks[i];
	}
	printf("\n--- Student details (Using array)---\n");
	printf("roll number: %d\n", roll_no);
	printf("name: %s\n",name);
	printf("Marks: ");
	for(i=0;i<5;i++)
	{
		printf("%d", marks[i]);
	}
	printf("\nTotal: %d\n",total );
	return 0;
}
