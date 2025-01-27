#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

int main() {
    mpz_t big_number;
    mpz_init_set_str(big_number, "42", 10); // Inicializa big_number com o valor 42

    // Obter a representação binária em string
    char *binary_representation = mpz_get_str(NULL, 2, big_number);

    // Converter a string binária para um inteiro em base 10
    int decimal_value = (int)strtol(binary_representation, NULL, 2);
    int aux = atoi(binary_representation);

    // Exibir os resultados
    printf("Representação binária: %s\n", binary_representation);
    printf("Valor decimal convertido: %d\n", decimal_value);
    printf("%d\n", aux);

    // Liberação de memória
    free(binary_representation);
    mpz_clear(big_number);

    return 0;
}

