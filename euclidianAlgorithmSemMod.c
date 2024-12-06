/*
* Euclidian Algorithm without '%'
*/

#include <stdio.h>

int main(){
	int a, b, c=0, aux1, auxA, auxB, count=0;

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
		count++;
		printf("%d = %d - %d\n", c, a, b);
		a = c;
		if(c < b){
			a = b;
			b = c;
			c = a - b;
			count++;
			printf("%d = %d - %d\n", c, a, b);
		}
	}while(c != b && c != 1);
	printf("gcd(%d, %d) = %d\nOperacoes: %d\n", auxA, auxB, c, count);
	
	return 0;
}
