/*
 * C programm to generate a giant number (string) with a desired size
 * Compile like this: $gcc -Wall numeroGiganormicoDesejado.c -lm -o numeroGiganormicoDesejado.x 
 * If you want to copy the output to clipboard: ./numeroGiganormicoDesejado.x n | xclip -selection clipboard
 * To install xclip: sudo apt-get install xclip
 * Explanetion about line 37 formula: POMMERSHEIM, James. Number Theory. EUA: Jhon Wiley & Sons, Inc, 2010. p. 400
 * */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(int argc, char *argv[]){
	int n, aux;
	srand(time(NULL));

	if(argc != 2){
		printf("Erro! Run like this: $ ./numeroGiganormicoDesejado.x n\n");
		exit(1);
	}
	n = atoi(argv[1]);
	char s[n];

	for(int i=0; i<n; i++){
		if(i==0){
			aux = 1 + rand() % (9 - 1 + 1); //Generate pseudo random numbers between 1 and 9
			s[i] = (char) aux;
		}else{
			aux = rand() % 10;
			s[i] = (char) aux;
		}
	}

	for(int i=0; i<n; i++){
		printf("%d", s[i]);
	}
	printf("\nY = %f\n", 13.24 * pow(n, 0.333333333) + 1928.6);

	return 0;
}
