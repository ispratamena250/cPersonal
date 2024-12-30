#include <stdio.h>

int main() { //Exemplo de leitura binária
    FILE *file;
    int data[5];

    // Abre o arquivo no modo binário para leitura
    file = fopen("dados.bin", "rb");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    // Lê 5 inteiros do arquivo
    fread(data, sizeof(int), 5, file);

    // Exibe os dados lidos
    for (int i = 0; i < 5; i++) {
        printf("Valor %d: %d\n", i + 1, data[i]);
    }

    // Fecha o arquivo
    fclose(file);

    return 0;
}

