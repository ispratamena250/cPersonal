#include <stdio.h>

void bobbleSort(int xs[], int n){
	int aux, flag;

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
		if(!flag){
			break;
		}
	}
}

void imprime(int xs[], int n){
	for(int i=0; i<n; i++){
		printf("%d ", xs[i]);
	}
	printf("\n");
}

int main(){
	int xs[] = {4, 6, 8, 10, 34, 21, 1};

	imprime(xs, 7);

	bobbleSort(xs, 7);

	imprime(xs, 7);

	printf("\n");
	return 0;
}
