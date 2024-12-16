#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 100

int main(){
	char s[TAM], c2[TAM];

	fgets(s, sizeof(s), stdin);
	fgets(c2, sizeof(c2), stdin);

	for(int i=0; i<strlen(s); i++){
		printf("%c ", s[i]);
	}
	printf("\n");

	for(int i=0; i<strlen(c2); i++){
		printf("%c ", c2[i]);
	}
	printf("\n");

	return 0;
}
