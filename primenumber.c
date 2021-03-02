#include <stdio.h>
int main (){
	int num;
	int prime=0;
	int counter;
	printf("enter your number.\n");
	scanf("%d", &num);
	for (counter=2; counter<num ; counter++) {
	
		if (num%counter == 0)
		prime++;}
	
	if (prime==0)
	printf("Your number is a prime number.\n");
	else 
	printf("Your number is not a prime number.\n");
}
