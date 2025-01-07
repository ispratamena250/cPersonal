/*
 *  Programa que mostra a matriz da classe de equivalência de um número desejado.
 *  Complie assim: $ gcc -Wall matrizClasseEquivalencia_semFruFru.c -o matrizClasseEquivalencia_semFruFru.x
 *  Rode: $ ./matrizClasseEquivalencia_semFruFru.x n
 * */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[2]){
  if(argc != 2){
    printf("Erro! Compile assim: $ ./matrizClasseEquivalencia_semFruFru.x n\n");
    exit(1);
  }
  int n = atoi(argv[1]);
  int count=0;
  int matriz[n][n];

  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      matriz[i][j] = count;
      count++;
    }
  }
  for(int i=0; i<n; i++){
    printf("\n");
    for(int j=0; j<n; j++){
      printf("%d ", matriz[j][i]);
    }
  }

  printf("\n");
  return 0;
}
