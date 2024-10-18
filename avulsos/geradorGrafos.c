//Código que gera grafos de tamanhos aleatórios com sintaxe adequada
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(){
	srand(time(NULL)); //Gera números aleatórios com base no timer da máquina
	int aux = rand() % 100; //O valor de 100 pode ser mudado a depender do tamanho do grafo desejado

	for(int i=1; i<=aux; i++){
		printf("'x%d': []\n", i);
	}
	
	return 0;
}
