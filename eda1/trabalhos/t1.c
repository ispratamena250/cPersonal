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
void distribuir(int q);
void geraMatriculas(int random);
void pulaLinha();
void palavraLonga(long int tam, int TAM);
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
	int q = 0;
	char sabores[TAM_SABORES];
	char* controler = "-1";
	srand(time(NULL));

	printf("Quantidade para produzir: ");
	scanf("%d", &q);
	printf("Sabores (-1 para terminar): ");
	//fprintf(file1, "-0\n");
	//@
	do{
		scanf("%s", sabores);
		palavraLonga(strlen(sabores), TAM_SABORES);
		//fprintf(file1, "%s\n", sabores);
		//@

	}while(strcmp(sabores, controler) != 0);

	distribuir(q);	
	
	pulaLinha();
}

void distribuir(int q){
	int quantAlunos = rand()%200;
	
	geraMatriculas(file, quantAlunos);

	
	

	pulaLinha();
}

void geraMatriculas(int random){
	srand(time(NULL));
	char matricula[10];

	for(int i=0; i<random; i++){
		for(int j=0; j<10; j++){
			matricula[j] = rand()%10;
		}
		//fprintf(file, "%s\n", matricula);
		//@
	}

	//fprintf(file, "-2\n");
	//@
}

void pulaLinha(){ printf("\n\n"); }

void palavraLonga(long int len, int TAM){
	if(len >= TAM){
		printf("Palavra muito longa!");
		pulaLinha();
		exit(1);
	}
}

void clear(){ system("cls || clear"); }
