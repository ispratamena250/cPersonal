#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "ponderedGraph_adjacentMatrixHeader.h"

#define MAX 100
#define V 10
int visited[MAX];

typedef struct grafo *Grafo;
struct grafo{
    int **ponteiro;
    int vertices;
    int arestas;
};

//Prototypes
void dfs(Grafo g, int e, int x, int y);

int main(){
    srand(time(NULL));
    int x, y;
   
    Grafo g = inicializaGrafo(V);

    memset(visited, 0, V*sizeof(visited[0]));

    for(int i=0; i<V; i++){
        for(int j=0; j<V; j++){
            int z = rand() % 100;
            insereArcoGrafo(g, i, j, z);
        }
    }

    printf("End: ");
    scanf("%d %d", &x, &y);

    //imprimeGrafo(graph);
    imprimeMatrizAdjacencia(g);
    printf("\n\n");

    int begin = 0;
    printf("Vertice %d: ", begin);
    dfs(g, begin, x, y);

    liberaGrafo(g);

    printf("\n");
    return 0;
}

void dfs(Grafo g, int e, int x, int y){
    int w=0;
    visited[e] = 1;
    printf("%d ", e);

    for(int i=0; i<g->vertices; i++){
        if(g->ponteiro[e][i] != 0 && visited[i] == 0){
            dfs(g, i, x, y);
            w += g->ponteiro[e][i];
            if(e == x && i == y){
                printf("found");
                //envia w para o vetor com os pesos de cada caminho válido
            }
        }
    }
}