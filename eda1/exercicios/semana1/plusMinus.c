#include<stdio.h>

int main(){
	int z=0, countI=0, countN=0, countZ=0;
	float ansI, ansN, ansZ;

	scanf("%d", &z);

	int arr[z];

	for(int i=0; i<z; i++){
		int aux;
		scanf("%d", &aux);
		arr[i] = aux;
	}

	for(int i=0; i<z; i++){
		if(arr[i] > 0){
			countI++;
		}else if(arr[i] < 0){
			countN++;
		}else{
			countZ++;
		}
	}

	ansI = (float)countI/z;
	ansN = (float)countN/z;
	ansZ = (float)countZ/z;

	printf("%.6f\n%.6f\n%.6f", ansI, ansN, ansZ);

	printf("\n");
	return 0;
}
