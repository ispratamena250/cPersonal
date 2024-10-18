//Código que gera grafos de tamnhos aleatórios com sintaxe adequada
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(){
	int num;

	srand(time(NULL)); //Gera números aleatórios com base no timer da máquina
	
	for(int i=0; i<10; i++){
		num = rand() % 100;
		printf("%d  ", num);
	}
	printf("\n");

	return 0;
}
