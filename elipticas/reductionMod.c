/*
* Algoritmo que implementa a redução de um número mod n
* Compile assim: $ gcc -Wall reductionMod.c -o reduction
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[3]){ //Ok. Isso foi burro.
	int a, b, aux, auxB;

	if(argc != 3){
		printf("Erro! Compile assim: $ reductionMod b a\n");
		exit(1);
	}
	a = atoi(argv[2]);
	b = atoi(argv[1]);
	auxB = a;

	aux = b%a;
	if(aux < 0){
		printf("%d mod(%d) = %d\n", b, a, aux+auxB);
	}else{
		printf("%d mod(%d) = %d\n", b, a, aux);
	}

	return 0;
}
