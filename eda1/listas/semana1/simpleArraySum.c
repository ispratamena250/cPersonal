#include <stdio.h>

int main(){
	int z=0, sum=0;

	scanf("%d", &z);

	int ar[z];

	for(int i=0; i<z; i++){
		int aux;
		scanf("%d", &aux);
		ar[i] = aux;
	}

	for(int i=0; i<z; i++){
		sum += ar[i];
	}

	printf("%d", sum);

	printf("\n");
	return 0;
}
