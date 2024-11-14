/*
 * C program to implement the Euclidian Algorithm to find the greatest commum divisor between tow natural numbers
 * */
#include <stdio.h>

int main(){	
	int a, b, rest, count=1, aux;
	
	printf("Type tow natural numbers: ");
	scanf("%d %d", &a, &b);

	if(a < b){
		aux = a;
		a = b;
		b = aux;
	}
	printf("gcd(%d, %d)\n", a, b);
	while(b != 0){
		printf("%d: (%d, %d)\n", count, a, b);
		rest = a % b;
		a = b;
		b = rest;
		count++;
	}
	printf("gcd: %d\n", a);
	
	return 0;
}
