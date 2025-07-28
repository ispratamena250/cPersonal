/*
* Autor: Isaac Menezes Pereira, 190088885
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "ponderedGraph_adjacentMatrixHeader.h"

#define MAX 100
#define V 10
int visited[MAX], qPaths=0; 

typedef struct grafo *Grafo;
struct grafo{
    int **ponteiro;
    int vertices;
    int arestas;
};

//Prototypes
void distribute(int path);
void populateGraph(Grafo g, int z);
void dfs(Grafo g, int e, int target, int caminho[], int profundidade, int cost);

int main(){
    srand(time(NULL));
    int target=0, begin=0, profundidade=0, cost=0, caminho[MAX], path=0;

    Grafo g = inicializaGrafo(V);

    memset(visited, 0, V*sizeof(visited[0]));

    populateGraph(g, 45); //45% 

    printf("Target (between 0 and 9): ");
    scanf("%d", &target);
    if(target > 9 || target < 0){
        printf("Error\n");
        exit(1);
    }else if(target == 0){
        distribute(target);
    }

    //imprimeMatrizAdjacencia(g);

    dfs(g, begin, target, caminho, profundidade, cost);

    printf("Choice (number of path): ");
    scanf("%d", &path);

    distribute(path);

    liberaGrafo(g);

    printf("\n");
    return 0;
}

void distribute(int path){
    int boxesTotal, idTotal;

    boxesTotal = rand() % 200;
    idTotal = rand() % 200;

    if(path == 0){
        printf("Total of meal boxes: %d\n", boxesTotal);
        printf("Total of students: %d\n", idTotal);
        exit(1);
    }

    if(boxesTotal > idTotal){
        if(boxesTotal - idTotal < path){
            printf("Pode processar!\n");    
        }else{
            printf("Tem marmita!\n");
        }
    }else{
        printf("Pode processar!\n");
    }

    printf("Total of meal boxes: %d\n", boxesTotal);
    printf("Total of students: %d", idTotal);
}

void populateGraph(Grafo g, int z){
    srand(time(NULL));
    int total = floor((z/100.0) * (V*V)), elements[V*V];
    
    memset(elements, 0, (V*V)*sizeof(elements[0]));

    for(int i=0; i<total; i++){
        int random = rand() % 100;
        elements[random] = random;
    }
    
    for(int i=0; i<V; i++){
        for(int j=0; j<V; j++){
            int random = rand() % (V*V);
            insereArcoGrafo(g, i, j, elements[random]);
        }
    }
}

void dfs(Grafo g, int e, int target, int caminho[], int profundidade, int cost){
    int w=0;
    visited[e] = 1;
    caminho[profundidade] = e;
    profundidade++;

    if(e == target){ //Found
        qPaths++;
        printf("-->Path %d: ", qPaths);
        for(int i=0; i<profundidade; i++){
            printf("%d ", caminho[i]);
        }
        printf("\nCost: %d\n\n", cost);
    }else{
        for(int i=0; i<g->vertices; i++){
            if(g->ponteiro[e][i] != 0 && !visited[i]){
                w = g->ponteiro[e][i];
                dfs(g, i, target, caminho, profundidade, cost+w);
            }
        }
    }

    visited[e] = 0; 
}