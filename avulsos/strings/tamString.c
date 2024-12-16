#include <stdio.h>
#include <stdlib.h>

int main(){
	int count = 0;
	char aux[1000];	

	printf("Digite: ");
	fgets(aux, sizeof(aux), stdin);
	while(aux[count] != '\0'){
		count++;
	}

	printf("Count: %d\n", count-1);

	return 0;
}
