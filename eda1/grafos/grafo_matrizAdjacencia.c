#include <stdio.h>
#include <stdlib.h>

typedef struct grafo *Grafo;

struct grafo{
    int **ponteiro;
    int vertices; //numero de vertices
    int arestas; //numero de arestas
};

Grafo inicializaGrafo(int num_vertices){
    Grafo g = malloc(sizeof *g);
    g->vertices = num_vertices;
    g->arestas = 0;
    g->ponteiro = malloc(num_vertices * sizeof(int *));

    for(int i=0; i<num_vertices; i++){
        g->ponteiro[i] = malloc(num_vertices * sizeof(int));
    }

    for(int i=0; i<num_vertices; i++){
        for(int j=0; j<num_vertices; j++){
            g->ponteiro[i][j] = 0;
        }
    }

    return g;
}

void insereArcoGrafo(Grafo g, int v, int novo){
    if(g->ponteiro[v][novo] == 0){
        g->ponteiro[v][novo] = 1;
        g->arestas++;
    }
}

void removerArcoGrafo(Grafo g, int v, int w){
    if(g->ponteiro[v][w] == 1){
        g->ponteiro[v][w] = 0;
        g->arestas--;
    }
}

void imprimeGrafo(Grafo g){
    for(int i=0; i<g->vertices; i++){
        printf("Vertices %2d: ", i);
        for(int j=0; j<g->vertices; j++){
            if(g->ponteiro[i][j] == 1){
                printf("%2d -> ", j);
            }
        }
        printf("\n");
    }
}

Grafo liberaGrafo(Grafo g){
    for(int i=0; i<g->vertices; i++){
        free(g->ponteiro[i]);
        g->ponteiro[i] = NULL;
    }

    free(g->ponteiro);
    g->ponteiro = NULL;
    free(g);

    return NULL;
}

int main(){
    Grafo grafo = inicializaGrafo(6);

    insereArcoGrafo(grafo, 0, 1);
    insereArcoGrafo(grafo, 0, 5);
    insereArcoGrafo(grafo, 1, 2);
    insereArcoGrafo(grafo, 2, 1);
    insereArcoGrafo(grafo, 2, 3);
    insereArcoGrafo(grafo, 3, 3);
    insereArcoGrafo(grafo, 3, 4);
    insereArcoGrafo(grafo, 3, 5);
    insereArcoGrafo(grafo, 4, 0);
    insereArcoGrafo(grafo, 5, 2);
    insereArcoGrafo(grafo, 5, 4);

    imprimeGrafo(grafo);

    liberaGrafo(grafo);

    printf("\n");
    return 0;
}