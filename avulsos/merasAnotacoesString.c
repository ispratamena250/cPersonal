/*
 * Um programa em C para implementar a lógica de operações númericas a partir de strings
 * */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char s1[100], s2[100];

	fgets(s1, sizeof(s1), stdin);
	//s1[strcspn(s1, "\n")] = '\0'; //Remove o \n
	fgets(s2, sizeof(s2), stdin);
	//s2[strcspn(s2, "\n")] = '\0'; //Remove o \n

	//Esse código acabou sendo deixado de lado e serve apenas como anotação	

	return 0;
}
