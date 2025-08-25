#include<stdio.h>
int main(){
	int roll_no;
	char name[50];
	int marks[30],i,total=0;
	printf("Enter roll number");
	scanf("%d",&roll_no);
	printf("Enter name\n");
	scanf("%s",name);
	printf("Enter the marks of 5 students:");
	for(i=0;i<5;i++){
		scanf("%d",&marks[i]);
		
		total += marks[i];
	}
	printf("/******Student details******/\n");
	printf("Roll no: %d\n",roll_no);
	printf("Name: %s\n",&name);
	for (i=0;i<5;i++){
		printf("Marks of the students %d: %d\n",i+1,marks[i]);
	}
	printf("Total marks: %d\n",total);
	return 0;
}
