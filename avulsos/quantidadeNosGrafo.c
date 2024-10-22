//Código que gera a sequência da quantidade crescente dos nós em um grafo e armazena em um arquivo
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
	FILE *arquivo = fopen("arquivoGrafos.txt", "w");
	FILE *gnuplot;
	int deposito=1, count=0, op, aux=0;

	if(argc != 2){
		printf("Erro! Execute como '$ ./quantidadeNosGrafo op'\n");
	}else{
		if(arquivo == NULL){
			printf("Erro ao abrir arquivo!\n");
			return 1;
		}

		op = atoi(argv[1]);
		if(op < 1){
			printf("Erro! Forneca um valor maior que 0\n");
			exit(1);
		}

		if(op == 1){
			printf("Sequência de pontos: %d\n", deposito); 
	        }else{
	                printf("Sequência de pontos: %d ", deposito);
	                while(count != (op - 1)){
        	                deposito = (deposito + 1)  + deposito;
				aux++;
				fprintf(arquivo, "%d\t%d\n", aux, deposito); //Escrita no arquivo
	                        count++;
                        	printf("%d ", deposito);                        
                	}
        	        printf("\n");
			gnuplot = popen("gnuplot -persistent", "w"); //Abrindo gnuplot
			if(gnuplot == NULL){
				printf("Erro ao abrir instancia(pipe) de gnuplot!\n");
				return 1;
			}
			fprintf(gnuplot, "set xlabel 'Grafos em ordem crescente'\n");
			fprintf(gnuplot, "set ylabel 'Quantidade de pontos'\n");
			fprintf(gnuplot, "set title 'Análise da quantidade crescente de pontos em um grafo triangular'\n");
			fprintf(gnuplot, "set key top left\n");
			fprintf(gnuplot, "plot 'arquivoGrafos.txt' using 1:2  with lp pt 7 lc rgb 'red' title 'Quant pontos'\n");
	       }
	}
	fclose(arquivo);

	return 0;
}
