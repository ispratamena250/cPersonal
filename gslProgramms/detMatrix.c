/*
* Para achar a esquação geral de uma reta, calcula-se a matriz 3x3 seguinte
* x	y	1
* xa	ya	1
* xb	yb	1
*/

#include <stdio.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_linalg.h>

int main() {
    // Cria uma matriz 3x3
    gsl_matrix *A = gsl_matrix_alloc(3, 3);

    // Preenche a matriz com valores
    gsl_matrix_set(A, 0, 0, 6.0);
    gsl_matrix_set(A, 0, 1, 1.0);
    gsl_matrix_set(A, 0, 2, 1.0);

    gsl_matrix_set(A, 1, 0, 4.0);
    gsl_matrix_set(A, 1, 1, -2.0);
    gsl_matrix_set(A, 1, 2, 5.0);

    gsl_matrix_set(A, 2, 0, 2.0);
    gsl_matrix_set(A, 2, 1, 8.0);
    gsl_matrix_set(A, 2, 2, 7.0);

    // Mostra a matriz
    printf("Matriz A:\n");
    for (size_t i = 0; i < 3; i++) {
        for (size_t j = 0; j < 3; j++) {
            printf("%g ", gsl_matrix_get(A, i, j));
        }
        printf("\n");
    }

    // Realiza a decomposição LU
    gsl_permutation *p = gsl_permutation_alloc(3);
    int signum;
    gsl_linalg_LU_decomp(A, p, &signum);

    // Calcula o determinante
    double det = gsl_linalg_LU_det(A, signum);
    printf("\nDeterminante: %g\n", det);

    // Libera memória
    gsl_permutation_free(p);
    gsl_matrix_free(A);

    return 0;
}

