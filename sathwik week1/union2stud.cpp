#include<stdio.h>

int main() {
	int roll_no;
	char name[50];
	int marks[5],total=0;
	int i;

	printf("Enter Roll no: ");
	scanf("%d", &s.roll_no);
	
	printf("Enter Name: ");
	scanf("%[^\n]",s.name);
	
	
	for(i=0; i<5;i++){
		printf("Enter Marks for subject %d: ",i+1);
		scanf("%d",&temp_marks[i]);
		total += marks[i];
	}
	printf("\n--- Student details (Using array)---\n");
	printf("roll number: %d\n", roll_no);
	printf("name: %s\n",name)
	printf("Marks: ");
	for(i=0;i<5;i++)
	{
		printf("%d", marks[i]);
	}
	printf("\nTotal: %d\n",total );
	getch();
	return 0;
}
