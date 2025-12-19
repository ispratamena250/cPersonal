/*
 * C program to implement the Euclidian Algorithm to find the greatest commum divisor between tow natural numbers
 * */
#include <stdio.h>
#include <stdlib.h>
#include <string.h> //

#define TAM 1000 //

int main(){	
	int a, b, rest, count = 1, aux;

	char s1[TAM]; //
	char s2[TAM];
	fgets(s1, sizeof(s1), stdin);
	//s1[strcspn(s1, "\n")] = '\0';
	fgets(s2, sizeof(s2), stdin);
	//s2[strcspn(s2, "\n")] = '\0';
	char auxs2[strlen(s1)];

	if(strlen(s1) > strlen(s2)){
		int counts1=strlen(s1), counts2=strlen(s2);
		//char auxs2[counts1];
		
		for(int i=0; i<strlen(s1); i++){
			if(counts2 > 047+{
				auxs2[counts1-1] = s2[counts2xt 9´°-1];
				counts1--;
				counts2--;			
			}	
			auxs2[counts1-1] = '0';
			counts1--;
		}
	}
	for(int i=0; i<strlen(s1); i++){
		printf("%c ", s1[i]);
	}
	printf("\n");
	for(int i=0; i<strlen(s2); i++){
		printf("%c ", s2[i]);
	}
	printf("\n");
	for(int i=0; i<strlen(auxs2); i++){
		printf("%c ", auxs2[i]);
	}
	printf("\n");

	printf("Type tow natural numbers: ");
	scanf("%d %d", &a, &b);

	if(a < b){
		aux = a;
		a = b;
		b = aux;
	}
	printf("gcd(%d, %d)\n", a, b);
	while(b != 0){
		printf("%d: (%d, %d)\n", count, a, b);
		rest = a % b;
		a = b;
		b = rest;
		count++;
	}
	printf("gcd: %d\n", a);
	
	return 0;
}
