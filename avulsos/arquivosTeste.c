#include <stdio.h>
#include <stdlib.h>

int main(){
	char texto[] = "Ola mundo";
	char buffer[sizeof(100)];

	FILE *arquivo = fopen("file.txt", "w");
	if(arquivo == NULL){
		printf("Erro\n");
		return 1;
	}

	fprintf(arquivo, "%s\n", texto); //Escrita no arquivo
	for(int i=0; i<10; i++){ //Escrita no arquivo
		fprintf(arquivo, "%d\n", i);
	}
	fclose(arquivo);

	arquivo = fopen("file.txt", "r");
	if(arquivo == NULL){
		printf("Erro\n");
		return 1;
	}

	//fgets(buffer, sizeof(buffer), arquivo); //Lê apenas uma linha
	printf("Conteúdo: \n");
	while(fgets(buffer, sizeof(buffer), arquivo) != NULL){
		printf("%s", buffer);
	}
	//printf("Conteudo: %s\n", buffer); //Imprime apenas uma linha lida
	fclose(arquivo);

	return 0;
}
