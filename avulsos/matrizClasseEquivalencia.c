/*
 * Programa para printar a matriz da classe de equivalência de algum número natural desejado.
 * Compile como: gcc -Wall matrizClasseEquivalencia.c -o matrizClasseEquivalencia
 * Execute como: $ ./matrizClasseEquivalencia mod
 * O termo 'mod' é a classe de equivalência desejada!
 * */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	int mod, count=0;

	if(argc != 2){
		printf("Erro! Execute como: $./matrizClasseEquivalencia mod\n");
		exit(1);
	}
	mod = atoi(argv[1]);
	int classe[mod][mod];

	for(int i=0; i<mod; i++){
		for(int j=0; j<mod; j++){
			classe[i][j] = count;
			count++;
		}
	}
	for(int i=0; i<mod; i++){
		printf("\n");
		for(int j=0; j<mod; j++){
			printf("%i\t", classe[j][i]); //É APENAS UMA MATRIZ TRANSPOSTA!!!!!!!
		}
	}
	printf("\n");
	
	return 0;
}
