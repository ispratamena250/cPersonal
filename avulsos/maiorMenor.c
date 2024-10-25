#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main(){	
	srand(time(NULL));
	int vetor[5], aux, aux2;
	
	for(int i=0; i<=5; i++){
		vetor[i] = rand() % 100;
	}
	printf("Vetor:\n");
	for(int i=0; i<=5; i++){
		printf("%d ", vetor[i]);
	}
	printf("\n");
	for(int i=0; i<=5; i++){
		if(i == 0){
			aux = vetor[0];
		}else if(aux > vetor[i]){
			aux = vetor[i];
		}
	}
	printf("Menor: %d\n", aux);

	for(int i=0; i<=5; i++){
		if(i == 0){
			aux2 = vetor[0];
		}else if(aux2 < vetor[i]){
			aux2 = vetor[i];
		}
	}
	printf("Maior: %d\n", aux2);

	return 0;
}
