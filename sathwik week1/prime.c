#include<stdio.h>
int main()
    {
    	int n;
    	printf("enter the number to check");
    	scanf("%d",&n);
    	int i,count=0;
    	for(i=2;i<=n;i++)
    		if(n%i==0){
    			count=1;
    			i=i+1;
			}
			


	if(count==0){
		printf("prime number");
		
	}
	else{
		printf("not a prime number");
	}
}
