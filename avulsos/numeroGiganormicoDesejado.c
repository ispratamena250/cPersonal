/*
 * C programm to generate a giant number (string) with a desired size
 * Run like this: $numeroGiganormicoDesejado n
 * It's needed the xclip installed: sudo apt-get install xclip 
 * */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char *argv[]){ //Terminar depois!!
	int n, aux;
	srand(time(NULL));

	if(argc != 2){
		printf("Erro! Run like this: $ ./numeroGiganormicoDesejado n\n");
		exit(1);
	}
	n = atoi(argv[1]);
	char s[n];

	for(int i=0; i<n; i++){
		aux = rand() % 10;
		sprintf(s, "%d", aux);
	}

	for(int i=0; i<n; i++){
		printf("%d ", s[i]);
	}
	printf("\n");

	return 0;
}
