#include <stdio.h>

int main(){
	int arr[6][6], v[36], count=0, v_contr[9] = {0, 1, 2, 6, 7, 8, 12, 13, 14}/*, contrLeft= 6, contrRight = 8*/;

	for(int i=0; i<6; i++){
		for(int j=0; j<6; j++){
			scanf("%d", &arr[i][j]);
			v[count++] = arr[i][j]; //Linearazing
		}
	}

	for(int i=0; i<36; i++)
		printf("%d ", v[i]);

	printf("\n\n");
	int aux=0;
	while(aux != 16){
		for(int i=0; i<9; i++)
			printf("%d\t", v_contr[i]);

		for(int i=0; i<=9; i++){
			if(i > 0 && (aux != 3)){
				v_contr[i-1] = v_contr[i-1] + 1;
				printf(" |%d <- ", aux);
			}else if(i > 0 && aux == 3){
				v_contr[i-1] = v_contr[i-1] + 3;
				printf(" |%d <- ", aux);
			}else if(i > 0 && aux == 7){
				v_contr[i-1] = v_contr[i-1] + 3;

			}else if(i > 0 && aux == 11){
				v_contr[i-1] = v_contr[i-1] + 3;

			}
		}
		
		aux++;
		printf("\n");
	}

	/*printf("\n\n");
	for(int i=0; i<16; i++){
		for(int j=0; j<=9; j++){
			if(j < 9) 
				printf("%d ", v[v_contr[j]]); 

			if(j > 0)  
				v_contr[j-1] = v_contr[j-1] + 1;
			
		}
		printf("\n");	
	}*/

	printf("\n");
	return 0;
}
