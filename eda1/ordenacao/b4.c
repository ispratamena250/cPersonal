#include <stdio.h>

void bubbleSort(int xs[], int n){
	int aux, troca;

	for(int i=0; i<n-1; i++){
		troca = 0;
		for(int j=0; j<n-i-1; j++){
			if(xs[j] > xs[j+1]){
				aux = xs[j];
				xs[j] = xs[j+1];
				xs[j+1] = aux;
				troca = 1;
			}
		}
		if(!troca){
			break;
		}
	}
}
