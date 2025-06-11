#include <stdio.h>

void b(int v[], int n){
	int aux, troca;

	for(int i=0; i<n-1; i++){
		troca = 0;
		for(int j=0; j<n-i-1; j++){
			if(v[j] > v[j+1]){
				aux = v[j];
				v[j] = v[j+1];
				v[j+1] = aux;
				troca = 1;
			}
		}
		if(!troca) break;
	}
}
