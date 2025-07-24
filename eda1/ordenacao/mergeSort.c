#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void mergeSort(int v[], int inicio, int fim);
void merge(int v[], int inicio, int meio, int fim);

int main(){
	int arr[] = {3, 7, 41, 1, 5, 2, 11, 37, -2, -5};	
	int n = sizeof(arr)/sizeof(arr[0]);

	mergeSort(arr, 0, n-1);

	for(int i=0; i<n; i++)
		printf("%d ", arr[i]);

	printf("\n");
	return 0;
}

void mergeSort(int v[], int inicio, int fim){
	int meio = floor((fim + inicio)/2);

	if(inicio < fim){
		mergeSort(v, inicio, meio);
		mergeSort(v, meio+1, fim);

		merge(v, inicio, meio, fim);
	}
}

void merge(int v[], int inicio, int meio, int fim){
	int tamanho = fim + 1;
	int vAux[tamanho];
	int i = inicio;
	int j = meio+1;
	int k = 0;

	while(i <= meio && j <= fim){
		if(v[i] <= v[j]){
			vAux[k++] = v[i++];
		}else{
			vAux[k++] = v[j++];
		}
	}

	while(i <= meio){
		vAux[k++] = v[i++];
	}
	while(j <= fim){
		vAux[k++] = v[j++];
	}

	for(i=inicio, k=0; i<=fim; i++, k++){
		v[i] = vAux[k];
	}
}
