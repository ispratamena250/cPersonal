#include <stdio.h>

void bs(int xs[], int n){
	int flag, aux;

	for(int i=0; i<n-1; i++){
		flag = 0;
		for(int j=0; j<n-i-1; j++){
			if(xs[j] > xs[j+1]){
				aux = xs[j];
				xs[j] = xs[j+1];
				xs[j+1] = aux;
				flag = 1;
			}
		}
		if(!flag) break;
	}
}
