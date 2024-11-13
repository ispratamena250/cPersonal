#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	int n, count=0;

	if(argc != 2){
		printf("Erro! Execute como: $./matrizSimples n\n");
		exit(1);
	}
	n = atoi(argv[1]);
	int m[n][n];

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			m[i][j] = count;
			count++;			
		}
	}
	for(int i=0; i<n; i++){
		printf("\n");
		for(int j=0; j<n; j++){
			printf("%i\t", m[i][j]);
		}
	}
	printf("\n");
	
	return 0;
}

