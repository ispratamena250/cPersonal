#include <stdio.h>
#include <stdlib.h>

int main(){
	int tam = 5;
	int *v;

	v = (int *)calloc(tam, sizeof(int));
	if(v == NULL){
		printf("Erro na alocação\n");
		return 1;
	}

	/*for(int i=0; i<5; i++){ //A função calloc inicia todos os elementos como zero
		v [i] = i * 8;
	}*/
	for(int i=0; i<5; i++){
		printf("%d ", v[i]);
	}
	printf("\n");

	free(v);

	return 0;
}
