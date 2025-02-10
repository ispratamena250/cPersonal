#include <stdio.h>

int main() { //Dados de exemplo: 10 20 30 40 50
    FILE *file;
    int num;

    // Abre o arquivo no modo de leitura
    file = fopen("numeros.txt", "r");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    // Lê números do arquivo
    printf("Numeros lidos:\n");
    while (fscanf(file, "%d", &num) != EOF) {
        printf("%d ", num);
    }

    // Fecha o arquivo
    fclose(file);

    printf("\n");
    return 0;
}

