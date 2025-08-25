#include<stdio.h>
int main()
    {
	
	int n;
	printf("enter the number to print the multiplication table");
	scanf("%d",&n);
	int i=1;
	for(i=1;i<=10;i++){
		int table=i*n;
		printf("the multiplies of givgen num is %d",table);
	}
	
		
}
