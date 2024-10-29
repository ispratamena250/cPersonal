#include <stdio.h>
int main(){
int num = 0;
	
	for(int i=1; i<=200; i++){
		num += i;	
	}
	printf("Valor acumulado no final dos depósitos: R$%d\n", num);

return 0;
}
