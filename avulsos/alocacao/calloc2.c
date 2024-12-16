#include <stdio.h>
#include <stdlib.h>

int main(){
	int aux=10;
	int *v, num;

	v = (int *)calloc(aux+2, sizeof(int));

	for(int i=0; i<5; i++){
		scanf("%d", &num);
		v[i] = num;
	}
	for(int i=0; i<7; i++){
		printf("%d ", v[i]);
	}
	printf("\n");

	return 0;
}
