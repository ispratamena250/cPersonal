#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "ponderedGraph_adjacentMatrixHeader.h"

#define MAX 100
#define V 10
int visited[MAX], weights[V*V], w=0; //talvez, weights precise ser alocado dinamicamente

typedef struct grafo *Grafo;
struct grafo{
    int **ponteiro;
    int vertices;
    int arestas;
};

//Prototypes
void dfs(Grafo g, int e, int target);
void jumpLine(int z);

int main(){
    srand(time(NULL));
    //int x, y;
    int target=0;
   
    Grafo g = inicializaGrafo(V);

    memset(visited, 0, V*sizeof(visited[0]));

    for(int i=0; i<V; i++){
        for(int j=0; j<V; j++){
            int z = rand() % 100;
            insereArcoGrafo(g, i, j, z);
        }
    }

    printf("End: ");
    //scanf("%d %d", &x, &y);
    scanf("%d", &target);
    //printf("%d %d", x, y);
    printf("%d", target);
    jumpLine(2);

    printf("Visited @1:\n");
    for(int i=0; i<MAX; i++){
        printf("%d|%d ", visited[i], i);
    }

    jumpLine(1);

    //imprimeGrafo(graph);
    imprimeMatrizAdjacencia(g);
    jumpLine(2);

    int begin = 0;
    printf("Vertice %d: ", begin);
    dfs(g, begin, target-2); //@
    
    jumpLine(2);

    printf("Weights:");
    jumpLine(1);
    for(int i=0; i<V*V; i++){
        printf("%d|%d ", weights[i], i);
    }

    jumpLine(2);

    printf("Visited @2:\n");
    for(int i=0; i<MAX; i++){
        printf("%d|%d ", visited[i], i);
    }

    liberaGrafo(g);

    jumpLine(1);
    return 0;
}

void dfs(Grafo g, int e, int target){
    visited[e] = 1;
    printf("%d ", e);

    for(int i=0; i<g->vertices; i++){
        if(g->ponteiro[e][i] != 0 && visited[i] == 0){
            dfs(g, i, target);
            w += g->ponteiro[e][i];
            printf("\nw%d\telement(%d, %d)%d", w, e, i, g->ponteiro[e][i]);
            //weights[i] = w; //@ precisamos dessa linha?
            if(e == target){
                //printf("found%d ", i);
                //envia w para o vetor com os pesos de cada caminho válido
                weights[i] = w;
            }else{
                weights[i] = -1;
            }
        }
    }
}

void jumpLine(int z){
    for(int i=0; i<z; i++)
        printf("\n");
}