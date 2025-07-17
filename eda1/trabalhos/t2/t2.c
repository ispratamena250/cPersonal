#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ponderedGraph_adjacentMatrixHeader.h"

#define TAM 5

int main(){
    srand(time(NULL));
    Grafo grafo = inicializaGrafo(TAM);

    for(int i=0; i<TAM; i++){
        for(int j=0; j<TAM; j++){
            int z = rand() % 100;
            insereArcoGrafo(grafo, i, j, (z == 0 ? -1 : z));
        }
    }

    imprimeGrafo(grafo);
    printf("\n");
    imprimeMatrizAdjacencia(grafo);
    liberaGrafo(grafo);

    printf("\n");
    return 0;
}