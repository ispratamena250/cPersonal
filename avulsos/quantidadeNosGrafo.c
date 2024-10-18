//Código que gera a sequência da quantidade crescente dos nós em um grafo
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
	int deposito=1, count=0, op;

	if(argc != 2){
		printf("Erro! Execute como '$ ./quantidadeNosGrafo op'\n");
	}else{
		op = atoi(argv[1]);

		if(op == 1){
			printf("Sequência de pontos: %d\n", deposito); 
	        }else{
	                printf("Sequência de pontos: %d ", deposito);
	                while(count != (op - 1)){
        	                deposito = (deposito + 1)  + deposito;
	                        count++;
                        	printf("%d ", deposito);                        
                	}
        	        printf("\n");
	       }
	}

	return 0;
}
