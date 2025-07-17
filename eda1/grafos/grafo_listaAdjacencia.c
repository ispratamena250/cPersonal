#include <stdio.h>
#include <stdlib.h>

typedef struct no No;
typedef struct grafo *Grafo;

struct no{
	No *prox;
	int rotulo;
};

struct grafo{
	int vertices;
	int arestas;
	No **ponteiro;
};

Grafo inicializaGrafo(int num_vertices){
	Grafo g = malloc(sizeof *g);
	g->vertices = num_vertices;
	g->ponteiro = malloc(num_vertices * sizeof(No *));
	
	for(int i=0; i<num_vertices; i++){
		g->ponteiro[i] = NULL; 
	}
	
	return g;
}

void insereArestas(Grafo g, int v, int novo){
	No *p;
	
	for(p=g->ponteiro[v]; p!=NULL; p=p->prox){
		if(p->rotulo == novo){
			return;
		}
	}
	
	p = malloc(sizeof(No));
	p->rotulo = novo;
	p->prox = g->ponteiro[v];
	g->ponteiro[v] = p;
	g->arestas++;
}

void imprimeGrafo(Grafo g){
	No *p;
	
	printf("%d %d\n", g->vertices, g->arestas);
	for(int i=0; i<g->vertices; i++){
		p = g->ponteiro[i];
		
		printf("\n Vertice %d: ", i);
		
		while(p){
			printf("%d -> ", p->rotulo);
			p = p->prox;
		}
	}
	
	printf("\n");
}

Grafo liberaGrafo(Grafo g){
	No *p;
	
	for(int i=0; i<g->vertices; i++){
		p = g->ponteiro[i];
		
		while(p != NULL){
			g->ponteiro[i] = p;
			p = p->prox;
			free(g->ponteiro[i]);
		}
		g->ponteiro[i] = NULL;
	}
	
	free(g->ponteiro);
	g->ponteiro = NULL;
	free(g);
	
	return NULL;
}

int main(){
	Grafo grafo = inicializaGrafo(6);
	
	insereArestas(grafo, 0, 1);
	insereArestas(grafo, 0, 4);
	insereArestas(grafo, 0, 5);
	insereArestas(grafo, 1, 0);
	insereArestas(grafo, 1, 2);
	insereArestas(grafo, 1, 2);
	insereArestas(grafo, 2, 1);
	insereArestas(grafo, 2, 1);
	insereArestas(grafo, 2, 3);
	insereArestas(grafo, 2, 5);
	insereArestas(grafo, 3, 2);
	insereArestas(grafo, 3, 3);
	insereArestas(grafo, 3, 4);
	insereArestas(grafo, 3, 5);
	insereArestas(grafo, 4, 0);
	insereArestas(grafo, 4, 3);
	insereArestas(grafo, 4, 5);
	insereArestas(grafo, 5, 0);
	insereArestas(grafo, 5, 2);
	insereArestas(grafo, 5, 3);
	insereArestas(grafo, 5, 4);

	imprimeGrafo(grafo);

	liberaGrafo(grafo);
	
	return 0;
}