#ifndef PODEREDGRAPH_ADJACENTMATRIXHEADER_H
#define PONDEREDGRAPH_ADJACENTMATRIXHEADER_H

typedef struct grafo *Grafo;

Grafo inicializaGrafo(int num_vertices);
void insereArcoGrafo(Grafo g, int v, int w, int peso);
void removerArcoGrafo(Grafo g, int v, int w);
void imprimeGrafo(Grafo g);
void imprimeMatrizAdjacencia(Grafo g);
Grafo liberaGrafo(Grafo g);

#endif
