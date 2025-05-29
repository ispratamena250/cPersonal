#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filaHeader.h"

int main(){
	char s[300];
	Fila* f = cria();

	printf("stdin: ");
	fgets(s, sizeof(s), stdin);

	s[strcspn(s, "\n")] = 0;

	printf("String: %s\nsizeof(): %ld\nstrlen(): %ld\n", s, sizeof(s), strlen(s));

	int count=0;
	for(int i=0; i<strlen(s); i++){
		if(s[i] != ' '){
			count++;
			if(i == 0){
				insere(f, s[0] - '0');
			}
			if(i > 1 && ((s[i] - '0') != (s[i-2] - '0'))){
				insere(f, (s[i] - '0'));	
				printf(" @%d->%c", i, s[i]);
			}
		}
	}

	printf("\nCount: %d\n", count);

	printf("\nFila:\n");
	listar(f);

	printf("\n");
	return 0;
}
