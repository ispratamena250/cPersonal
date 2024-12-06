/*
* Euclidian Algorithm without '%'
* Compile assim: $ gcc -Wall euclidianAlgorithmSemMod.c -o euclidianAlgorithmSemMod
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[3]){
	int a, b, c=0, aux1, auxA, auxB, count=0;
	
	if(argc != 3){
		printf("Erro! Execute assim: $ ./euclidianAlgorithmSemMod a b\n");
		exit(1);
	}	
	a = atoi(argv[1]);
	b = atoi(argv[2]);	

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
		//printf("%d = %d - %d\n", c, a, b);
		a = c;
		if(c < b){
			a = b;
			b = c;
			c = a - b;
			count++;
			//printf("%d = %d - %d\n", c, a, b);
		}
	}while(c != b && c != 1);
	printf("gcd(%d, %d) = %d\nOperacoes: %d\n", auxA, auxB, c, count);
	
	return 0;
}
