/*
 * C program that plot a grath to analise the grouth size of caracteres of diferent conversions of decimal numbers to binari numbers
 * Compile: $ gcc -Wall decSize_binSize_analisys.c -lgmp -o decSize_binSize_analisys.x
 * Run: $ ./decSize_binSize_analisys.x 
 * 
 * Observação:
 * O arquivo padra_decSize_binSize_analisys.txt é tratado no progama analisys_padrao_decBinSize.cpp em /estudoCpp/avulsos 
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gmp.h>

#define TAM 600

int main(){
  FILE *file = fopen("dados_decSize_binSize_analisys.txt", "w");
  if(file == NULL){
    printf("Error on openning dados_decSize_binSize_analisys.txt\n");
    exit(1);
  }

  FILE *gnuplot = popen("gnuplot -persistent", "w");
  if(gnuplot == NULL){
    printf("Error on openning gnuplot pipe\n");
    exit(1);
  }
  
  FILE *file2 = fopen("padrao_decSize_binSize_analisys.txt", "w");
  if(file2 == NULL){
    printf("Error on openning padrao_decSize_binSize_analisys.txt\n");
    exit(1);
  }

  FILE *plotFile = fopen("plot_decSize_binSize_analisys.gpl", "w");
  if(plotFile == NULL){
    printf("Error on openning plot_decSize_binSize_analisys.gpl\n");
    exit(1);
  }

  char s[TAM+1];
  
  for(int i=1; i<=TAM; i++){
    mpz_t n;
    mpz_init(n);

    sprintf(s, "%d", i);
    mpz_set_str(n, s, 10);
    char *bin = mpz_get_str(NULL, 2, n);
    //printf("bin: %s\t*bin: %d\n", bin, *bin); //Pensar sobre isso depois
    fprintf(file, "%s\t%s\t%zu\t%zu\n", s, bin, strlen(s), strlen(bin));
    //fprintf(file2, "%zu\n", strlen(bin)); //O resultado disso é tratado com a função fileComBarraN()  
    fprintf(file2, "%zu", strlen(bin)); //O resultado disso é tratado com a função fileSemBarraN() 

    mpz_clear(n);
    free(bin);
  }
  fclose(file);
  fclose(file2);

  fprintf(plotFile, "#Script de plotagem do programa decSize_binSize_analisys.c\n");
  fprintf(plotFile, "#Programa presente em /estudoC/elipticas\n\n");
  fprintf(plotFile, "reset\n"); //Primeiro plot
  fprintf(plotFile, "set terminal qt 1 #Primeira janela: força o gnuplot a carregar as duas janelas, necessário para o pipe plotar o dois gráficos\n");
  fprintf(plotFile, "set xrange [-10:610]\n");
  fprintf(plotFile, "set yrange [0:15]\n");
  fprintf(plotFile, "set xlabel 'Números em decimal'\n");
  fprintf(plotFile, "set ylabel 'Quantidade de bits na base 2'\n");
  fprintf(plotFile, "set title 'Decimal and binary: number of bits analisys'\n");
  fprintf(plotFile, "set style fill solid 1.0 border -1\n");
  fprintf(plotFile, "set boxwidth 0.8\n");
  fprintf(plotFile, "set style line 1 lc rgb 'black'\n");
  fprintf(plotFile, "plot 'dados_decSize_binSize_analisys.txt' u 1:4 t 'quantidade de bits' w boxes ls 1\n\n");
  fprintf(plotFile, "reset\n"); //Segundo Plot
  fprintf(plotFile, "set terminal qt 2 #Segunda janela: força o gnuplot a carregar as duas janelas, necessário para o pipe plotar o dois gráficos\n");
  fprintf(plotFile, "set key bottom right\n");
  fprintf(plotFile, "set xlabel 'Quantidade de bits das representações dos nº decimais'\n");
  fprintf(plotFile, "set ylabel 'Quantidade de bits das representações dos nº binários'\n");
  fprintf(plotFile, "set xrange [0:5]\n");
  fprintf(plotFile, "set yrange [0:12]\n");
  fprintf(plotFile, "set title 'Decimal and binary: number of bits analisys'\n");
  fprintf(plotFile, "plot 'dados_decSize_binSize_analisys.txt' u 3:4 t 'quantidade de bits' w p pt 7 lc rgb 'red'\n");
  fclose(plotFile);

  fprintf(gnuplot, "load 'plot_decSize_binSize_analisys.gpl'\n");
  fflush(gnuplot);
  fprintf(gnuplot, "pause -1\n");
  pclose(gnuplot);

  printf("\n");
  return 0;
}
