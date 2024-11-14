#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char c[100];

	fgets(c, sizeof(c), stdin);
	for(int i=0, j=strlen(c); i<strlen(c), j<0; i++, j--){
			printf("%c ", c[j]);
	}
	printf("\n");

	return 0;
}
