/*
* Referência: POMMERSHEIM, James. Number Theory. EUA: Jhon Wiley & Sons, Inc, 2010. p. 400 
* Para compilar: $ gcc -Wall factoringHugeNumbersY.c -lm -o factoringHugeNumbersY.x 
* Para rodar: $ ./factoringHugeNumbersY.x
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	int i;
	float y;

	FILE *file = fopen("dados_factoringHugeNumbersY.txt", "w");
	if(file == NULL){
		printf("Erro ao abrir dados_factoringHugeNumbersY.txt\n");
		exit(1);
	}
	
	for(i=10; i<=100000; i++){
		y = 13.24 * pow(i, 0.33333333) + 1928.6;
		fprintf(file, "%d\t%.2f\n", i, y);	
		i += 999;
	}
	fclose(file);

	FILE *gnuplot = popen("gnuplot -persistent", "w");	
	if(gnuplot == NULL){
		printf("Erro ao abrir pipe do gnuplot\n");
		exit(1);
	}

	fprintf(gnuplot, "set xrange [-10000:110000]\n");
	fprintf(gnuplot, "set yrange [0:3100]\n");
	fprintf(gnuplot, "set xlabel 'D'\n");
	fprintf(gnuplot, "set ylabel 'Y'\n");
	fprintf(gnuplot, "set title 'Visualização de difetentes valores de D'\n");
	fprintf(gnuplot, "set object 1 circle at 617, 2041 size 200 fillcolor 'black' fillstyle solid\n");
	fprintf(gnuplot, "set object 2 circle at 100, 1990 size 200 fillcolor 'red' fillstyle solid\n");
	fprintf(gnuplot, "set object 3 rectangle at 30936.4, 2800.27 size 70000, 340 front fillcolor 'black' fillstyle empty border lc 'black'\n");
	fprintf(gnuplot, "set label 1 'Ponto preto: D=100 e Y=1990;' at -1162.12, 2890.12\n");
	fprintf(gnuplot, "set label 2 'Ponto vermelho: D=617 e Y=2041.' at -1162.12, 2750.12\n");
	fprintf(gnuplot, "plot 'dados_factoringHugeNumbersY.txt' u 1:2 t 'Anos' w boxes\n");
	fflush(gnuplot);
	
	pclose(gnuplot);	

	return 0;
}
