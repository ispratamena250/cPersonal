#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE *file = fopen("file1.txt", "w");
	if(file == NULL){
		printf("Erro ao abrir arquivo\n");
		exit(1);
	}

	char s[50] = "teste";

	fprintf(file, "%s\n", s);
	fclose(file);

	return 0;
}
