#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char c[100];

	fgets(c, sizeof(c), stdin);
	int tam = strlen(c);

	for(int i=0; i<strlen(c); i++){
		printf("%c ", c[tam-1]);
		tam--;
	}
	printf("\n");

	return 0;
}
