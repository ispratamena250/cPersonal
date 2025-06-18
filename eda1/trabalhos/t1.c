#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "pilhaHeader.h"
#include "filaHeader.h"
#define TAM_SABORES 100

//Prototypes
void menu();
void produzir();
void distribuir();
void encerrarSistema();
void pulaLinha();
void palavraLonga(long int tam, int TAM);
void verificaArquivo(FILE* file, const char *mensagem);
void clear();

int main(){
	menu();

	printf("\n");
	return 0;
}

void menu(){
	int op = 0;

	while(1){
		printf("Opcoes:\n1 - Produzir marmitas\n2 - Distribuir marmitas\n3 - Encerrar\nEscolhe: ");
		scanf("%d", &op);
		getchar();

		switch(op){
			case 1:
				clear();
				produzir();
				break;
			case 2:
				clear();
				distribuir();
				break;
			case 3 : 
				exit(1);
				break;
			default:
				clear();
				printf("Opcao invalida\n\n");
				break;
		}
	}

}

void produzir(){
	FILE *file1 = fopen("logMarmitas.txt", "w");
	verificaArquivo(file1, "Erro ao abrir file1 em produzir() em modo 'w'");
	int q = 0;
	char sabores[TAM_SABORES];
	char* controler = "-1";

	printf("Quantidade para produzir: ");
	scanf("%d", &q);
	printf("Sabores (-1 para terminar): ");
	do{
		scanf("%s", sabores);
		palavraLonga(strlen(sabores), TAM_SABORES);
		fprintf(file1, "%s\n", sabores);
	}while(strcmp(sabores, controler) != 0);

	fclose(file1);
	pulaLinha();
}

void distribuir(){
	printf("distribuindo");

	pulaLinha();
}

void pulaLinha(){ printf("\n\n"); }

void palavraLonga(long int len, int TAM){
	if(len >= TAM){
		printf("Palavra muito longa!");
		pulaLinha();
		exit(1);
	}
}

void verificaArquivo(FILE* file, const char *mensagem){
	if(!file){
		clear();
		perror(mensagem);
		exit(1);
	}
}

void clear(){ system("cls || clear"); }
