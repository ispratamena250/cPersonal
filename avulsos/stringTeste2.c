#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char s[100];

	fgets(s, sizeof(s), stdin);

	for(int i=0; i<strlen(s); i++){
		printf("%c ", s[i]);
	}
	printf("\n");

	return 0;
}
