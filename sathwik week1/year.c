#include<stdio.h>
int main()
    {
	
	int year;
	printf("enter the year to check");
	scanf("%d",& year);
	if(year%4==0){
		printf("the given year is leap year");
	}
	else{
		printf("the given year is non leap year");
	}
		
}
