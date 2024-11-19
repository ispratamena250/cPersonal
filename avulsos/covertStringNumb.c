/*
 * Em C, os índices numéricos de um vetor de caracteres podem ser tratados normalmente sem necessidade de conversão
 * */

#include <stdio.h>

int main(){
	char c[5];
	//int v[5];

	for(int i=0; i<5; i++){
		scanf("%c", &c[i]);	
	}

	for(int i=0; i<5; i++){
		//v[i] = '0' + c[i];
		c[i] += 1;
	}

	for(int i=0; i<5; i++){
		printf("%c ", c[i]);
	}
	printf("\n");

	return 0;
}
