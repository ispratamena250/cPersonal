#include <stdio.h>

void i(int v[], int n){
	int i, j, atual;

	for(i=1; i<n; i++){
		atual = v[i];
		for(j=i; (j>0)&&(atual < v[j-1]); j--){
			v[j] = v[j-1];
		}
		v[j] = atual;
	}
}

void imprime(int v[], int n){
	for(int i=0; i<n; i++){
		printf("%d ", v[i]);
	}
}

int main(){
	int v[] = {29, 10, 14, 37, 13};

	imprime(v, 5);

	i(v, 5);

	printf("\n");
	imprime(v, 5);

	printf("\n");
	return 0;
}
