#include <stdio.h>
#include <gsl/gsl_matrix.h>

int main() {
    // Cria duas matrizes 2x2
    gsl_matrix *a = gsl_matrix_alloc(2, 2);
    gsl_matrix *b = gsl_matrix_alloc(2, 2);

    // Preenche as matrizes com valores
    gsl_matrix_set(a, 0, 0, 1.0);
    gsl_matrix_set(a, 0, 1, 2.0);
    gsl_matrix_set(a, 1, 0, 3.0);
    gsl_matrix_set(a, 1, 1, 4.0);

    gsl_matrix_set(b, 0, 0, 5.0);
    gsl_matrix_set(b, 0, 1, 6.0);
    gsl_matrix_set(b, 1, 0, 7.0);
    gsl_matrix_set(b, 1, 1, 8.0);

    // Realiza a multiplicação elemento por elemento
    gsl_matrix_mul_elements(a, b);

    // Imprime a matriz resultado
    printf("Resultado da multiplicação elemento por elemento:\n");
    for (size_t i = 0; i < 2; i++) {
        for (size_t j = 0; j < 2; j++) {
            printf("%g ", gsl_matrix_get(a, i, j));
        }
        printf("\n");
    }

    // Libera memória
    gsl_matrix_free(a);
    gsl_matrix_free(b);

    return 0;
}

