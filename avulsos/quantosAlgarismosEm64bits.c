/*
 * Programa que apenas checa (por curiosidade) quantos algarismos existem em um vetor com 2**64-1 posições.
 * Execute assim: gcc -Wall -lm quantosAlgarismosEm64bits.c -o quantosAlagarismosEm64bits.
 * */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){ //922337203685475808

	if(argc != 2){
		printf("Erro! Execute assim: $ ./quantosAlgarismosEm64bits s\n");
		exit(1);
	}
	char *s = argv[1];

	printf("Tamanho: %ld\n", strlen(s));

	return 0;
}
