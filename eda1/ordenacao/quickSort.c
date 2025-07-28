#include <stdio.h>

int particiona(int *v, int inicio, int final){
    int esq, dir, pivo, aux;

    esq = inicio;
    dir = final;
    pivo = v[inicio];

    while(esq < dir){
        while(esq <= final && v[esq] <= pivo){
            esq++;
        }
        while(dir >= 0 && v[dir] > pivo){
            dir--;
        }
        if(esq < dir){
            aux = v[esq];
            v[esq] = v[dir];
            v[dir] = aux;
        }
    }
    v[inicio] = v[dir];
    v[dir] = pivo;
    
    return dir;
}

void quickSort(int *v, int inicio, int fim){
    int pivo;

    if(fim > inicio){
        pivo = particiona(v, inicio, fim);
        quickSort(v, inicio, pivo-1);
        quickSort(v, pivo+1, fim);
    }
}

int main(){
    int arr[] = {98, 1, 45, 3, 2, 40, 7, 4, 11, 67, 21, 15};

    quickSort(arr, 0, 11);

    for(int i=0; i<11; i++)
        printf("%d ", arr[i]);

    printf("\n");
    return 0;
}