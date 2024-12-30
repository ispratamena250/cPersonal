/*
 * C program that plot a grath to analise the grouth size of caracteres of diferent conversions of decimal numbers to binari numbers
 * Compile: $ gcc -Wall decSize_binSize_analisys.c -lgmp -o decSize_binSize_analisys.x
 * Run: $ ./decSize_binSize_analisys.x 
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gmp.h>

#define TAM 200

int main(){
  FILE *file = fopen("dados_decSize_binSize_analisys.txt", "w");
  if(file == NULL){
    printf("Error on openning dados_decSize_binSize_analisys.txt\n");
    exit(1);
  }

  FILE *gnuplot = popen("gnuplot -persistent", "w") ;
  if(gnuplot == NULL){
    printf("Error on openning gnuplot pipe\n");
    exit(1);
  }
  
  FILE *file2 = fopen("padrao_decSize_binSize_analisys.txt", "w");
  if(file2 == NULL){
    printf("Error on openning padrao_decSize_binSize_analisys.txt\n");
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
    fprintf(file, "%s\t%s\t%zu\n", s, bin, strlen(bin));
    fprintf(file2, "%zu\n", strlen(bin));

    mpz_clear(n);
    free(bin);
  }
  fclose(file);
  fclose(file2);

  fprintf(gnuplot, "set xrange [-10:210]\n");
  fprintf(gnuplot, "set yrange [0:10]\n");
  fprintf(gnuplot, "set xlabel 'Números em decimal'\n");
  fprintf(gnuplot, "set ylabel 'Quantidade de bits na base 2'\n");
  fprintf(gnuplot, "set title 'Decimal and binary: size bit analisys'\n");
  fprintf(gnuplot, "set style fill solid 1.0 border -1\n");
  fprintf(gnuplot, "set boxwidth 0.8\n");
  fprintf(gnuplot, "set style line 1 lc rgb 'black'\n");
  fprintf(gnuplot, "plot 'dados_decSize_binSize_analisys.txt' u 1:3 t 'quantidade de bits' w boxes ls 1\n");
  fflush(gnuplot);

  pclose(gnuplot);

  printf("\n");
  return 0;
}
