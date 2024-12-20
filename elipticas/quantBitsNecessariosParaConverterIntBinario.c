#include <stdio.h>
#include <stdlib.h>

void naturais();
void potencias2();

int main(){
	int n, count=0;
	long long num;

	const char *filename2 = "potencias2.txt";
	FILE *file1 = fopen(filename2, "r");
	if(file1 == NULL){
		printf("O arquivo '%s' não existe. Será criado e o programa encerrado.\n", filename2);
		potencias2();
		printf("Arquivo criado.\n");
		exit(1);
	}

	printf("Numero desejado: ");
	scanf("%d", &n);
	while(fscanf(file1, "%lld", &num) && n>=num){
		printf("%lld\n", num);
		count++;
	}	
	printf("Quantidade de bits: %d\n", count);

	fclose(file1);

	return 0;
}

void naturais(){
	FILE *file1 = fopen("naturais.txt", "w");
	if(file1 == NULL){
		printf("Erro ao abrir file1\n");
		exit(1);
	}

	long long num=0;

	for(int i=0; i<=90000000; i++){ //Gera um arquivo de mais de 700MB
		fprintf(file1, "%lld\n", num+i);
	}

	fclose(file1);
}

void potencias2(){
	long long number, aux=2;
	
	const char *filename1 = "naturais.txt";
	FILE *file1 = fopen(filename1, "r");
	if(file1 == NULL){
		printf("O arquivo '%s' não existe. Será criado e o programa encerrado.\n", filename1);
		naturais();
		printf("Arquivo criado.\n");
		exit(1);
	}
	
	FILE *file2 = fopen("potencias2.txt", "w");
	if(file2 == NULL){
		printf("Erro ao abrir file2\n");
		exit(1);
	}

	while(fscanf(file1, "%lld", &number) && aux*2<=90000000){
		if(number == aux*2 || number == 1 || number == 2){
			fprintf(file2, "%lld\n", number);
			aux=number;
		}
	}

	fclose(file1);
	fclose(file2);
}
