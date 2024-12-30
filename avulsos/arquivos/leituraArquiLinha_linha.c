#include <stdio.h>

int main() { //Isso é apenas um exemplo.
    FILE *file;
    char buffer[100];

    // Abre o arquivo no modo de leitura
    file = fopen("meuarquivo.txt", "r");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    // Lê o arquivo linha por linha
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer); // Imprime cada linha lida
    }

    // Fecha o arquivo
    fclose(file);

    return 0;
}

