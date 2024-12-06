/*
 * Programa para printar a matriz da classe de equivalência de algum número natural desejado.
 * Compile como: gcc -Wall matrizClasseEquivalencia.c -o matrizClasseEquivalencia
 * Execute como: $ ./matrizClasseEquivalencia mod
 * O termo 'mod' é a classe de equivalência desejada!
 * */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	int mod;

	if(argc != 2){
		printf("Erro! Execute como: $./matrizClasseEquivalencia mod\n");
		exit(1);
	}
	mod = atoi(argv[1]);
	int count = (-3)*mod;
	int classe[mod][mod+2];

	for(int i=0; i<mod+2; i++){
		for(int j=0; j<mod; j++){
			classe[j][i] = count;
			count++;
		}
	}
	for(int i=0; i<mod; i++){
		printf("\n[... ");
		for(int j=0; j<mod+2; j++){
			if(j==mod+1){
				printf("%d ...]", classe[i][j]);
			}else{
				printf("%d\t", classe[i][j]); //É APENAS UMA MATRIZ TRANSPOSTA!!!!!!!
			}
		}
	}
	printf("\n");
	
	return 0;
}
