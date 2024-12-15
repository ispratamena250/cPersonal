/*
 * C programm to generate a giant number (string) with a desired size
 * Run like this: $numeroGiganormicoDesejado n
 * If you want to copy the output to clipboard: ./numeroGiganormicoDesejado n | xclip -selection clipboard
 * */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]){
	int n, aux;
	srand(time(NULL));

	if(argc != 2){
		printf("Erro! Run like this: $ ./numeroGiganormicoDesejado n\n");
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
		//sprintf(s, "%d", aux); //Errado
	}

	for(int i=0; i<n; i++){
		printf("%d", s[i]);
	}
	printf("\n");

	return 0;
}
