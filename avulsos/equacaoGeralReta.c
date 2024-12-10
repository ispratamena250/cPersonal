/*
* Código para gerar a equacao da reta a partir de dois pontos dados
* Compile assim: $ gcc -Wall equacaoGeralReta.c -o equacaoGeralReta x1 y1 x2 y2 
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[5]){
	float x1, y1, x2, y2, a, b;

	if(argc != 5){
		printf("Erro! Rode assim: $ ./equacaoGeralReta x1 y1 x2 y2\n");
		exit(1);
	}
	x1 = atof(argv[1]);
	y1 = atof(argv[2]);
	x2 = atof(argv[3]);
	y2 = atof(argv[4]);

	a = (y2 - y1)/(x2 -x1);
	b = y1 - a*x1;
	if(b > 0){
		printf("y = %.2fx + %.2f\n", a, b);
	}else{
		printf("y = %.2fx + %.2f\n", a, b*(-1));
	}

	return 0;
}
