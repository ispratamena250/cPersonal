/*
 *  Uma função em C que recebe três parâmetros e é possível acessar quantos desejar
 * */

#include <stdio.h>
#include <string.h>

typedef struct{
  int idade;
  char nome[100];
  float altura;
} Pessoa;

//Assinatura
Pessoa retornaPessoa(int idade, const char* nome, float altura);

int main(){

  for(int i=0; i<3; i++){
    int idade = i;
    char s[100] = "isaac";
    float altura = i/2;

    Pessoa p1 = retornaPessoa(idade, s, altura);

    printf("Idade: %d, Nome: %s, Altura: %.2f\n", p1.idade, p1.nome, p1.altura);
    printf("Idade: %d, Nome: %s\n", p1.idade, p1.nome);
    printf("Altura: %f\n", p1.altura);
    printf("\n\n");
  }

  printf("\n");
  return 0;
}

Pessoa retornaPessoa(int idade, const char* nome, float altura){
  Pessoa resultado;

  resultado.idade = idade+100;
  strcpy(resultado.nome, nome);
  resultado.altura = altura;

  return resultado;
}
