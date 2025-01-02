/*
* Progama para calcular o inverso modular entre dois números
*/

#include <stdio.h>
#include <stdlib.h>

// Função para calcular o Máximo Divisor Comum (MDC) e o coeficiente x pelo Algoritmo Estendido de Euclides
int gcdExtended(int a, int b, int *x, int *y) {
    if (a == 0) {
        *x = 0;
        *y = 1;
        return b;
    }

    int x1, y1; // Coeficientes para as chamadas recursivas
    int gcd = gcdExtended(b % a, a, &x1, &y1);

    // Atualiza os valores de x e y
    *x = y1 - (b / a) * x1;
    *y = x1;

    return gcd;
}

// Função para calcular o inverso modular
int modInverse(int a, int m) {
    int x, y; // Coeficientes que satisfazem a identidade de Bézout
    int gcd = gcdExtended(a, m, &x, &y);

    // O inverso modular existe apenas se o MDC(a, m) = 1
    if (gcd != 1) {
        printf("Inverso modular não existe.\n");
        return -1; // Retorna -1 para indicar que não há inverso
    }

    // Ajusta x para ser positivo (caso necessário)
    int inverse = (x % m + m) % m;
    return inverse;
}

int main(int argc, char* argv[]) {
    if(argc != 3){
    	printf("Erro! Execute como: ./inversoModular a m\n");
        exit(1);
    }    
    
    int a = atoi(argv[1]), m = atoi(argv[2]);

    int inverse = modInverse(a, m);
    if (inverse != -1) {
        printf("O inverso modular de %d módulo %d é: %d\n", a, m, inverse);
    }

    return 0;
}

