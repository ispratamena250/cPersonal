#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
	int vetor[5];
	srand(time(NULL));

	for(int i=0; i<5; i++){
		vetor[i] = rand() % 10;
	}

	for(int i=0; i<5; i++){
		printf("%d ", vetor[i]);
	}
	printf("\n");

	return 0;
}
