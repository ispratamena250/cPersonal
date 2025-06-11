#include <stdio.h>

void b(int xs[], int n){
	int aux, trocou;

	for(int i=0; i<n-1; i++){
		trocou = 0;
		for(int j=0; j<n-i-1; j++){
			if(xs[j] > xs[j+1]){
				aux = xs[j];
				xs[j] = xs[j+1];
				xs[j+1] = aux;
				trocou = 1;
			}
		}
		if(!trocou){
			break;
		}
	}
}
