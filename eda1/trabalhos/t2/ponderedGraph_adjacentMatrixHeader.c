/*
* Autor: Isaac Menezes Pereira, 190088885
*/

#include <stdio.h>
#include <stdlib.h>
#include "ponderedGraph_adjacentMatrixHeader.h"

typedef struct grafo *Grafo;

struct grafo{
    int **ponteiro;
    int vertices; 
    int arestas; 
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

void insereArcoGrafo(Grafo g, int v, int w, int peso){
    if(g->ponteiro[v][w] == 0){
        g->ponteiro[v][w] = peso;
        g->arestas++;
    }else{
        g->ponteiro[v][w] = peso;
    }
}

void removerArcoGrafo(Grafo g, int v, int w){
    if(g->ponteiro[v][w] != 0){
        g->ponteiro[v][w] = 0;
        g->arestas--;
    }
}

void imprimeGrafo(Grafo g){
    for(int i=0; i<g->vertices; i++){
        printf("Vertices %2d: ", i);
        for(int j=0; j<g->vertices; j++){
            if(g->ponteiro[i][j] != 0){
                printf("%2d(%d) -> ", j, g->ponteiro[i][j]);
            }
        }
        printf("\n");
    }
}

void imprimeMatrizAdjacencia(Grafo g){
    for(int i=0; i<g->vertices; i++){
        printf("\n");
        for(int j=0; j<g->vertices; j++){
            printf("%d\t", g->ponteiro[i][j]);
        }
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