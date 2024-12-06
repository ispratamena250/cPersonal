/*
* Euclidian Algorithm without '%'
*/

#include <stdio.h>

int main(){
	int a, b, c=0, aux1, auxA, auxB;

	printf("Type two natural numbers: ");
	scanf("%d %d", &a, &b);
	auxA = a;
	auxB = b;	

	if(a < b){
		aux1 = a;
		a = b;
		b = aux1;
	}
	do{
		c = a - b;
		printf("%d = %d - %d\n", c, a, b);
		a = c;
		if(c < b){
			a = b;
			b = c;
			c = a - b;
			printf("%d = %d - %d\n", c, a, b);
		}
	}while(c != b && c != 1);
	printf("gcd(%d, %d) = %d\n", auxA, auxB, c);
	
	return 0;
}
