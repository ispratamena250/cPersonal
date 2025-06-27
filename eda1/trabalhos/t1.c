#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include "pilhaStringsHeader.h"
#include "filaStringsHeader.h"

#define SIZE_FLAVORS 100 
Stack* flavorStack;
Queue* idQueue;

//Prototypes 
void menu(); 
int produce(); 
void distribute(int guess); 
char *generateId(); 
void clearLine(int q); 
void longString(long int tam, int TAM); 
void clearScreen(); 
void removeSpaces(char *s);
void verifyFile(FILE *file, char *whichFunction, char *whichOption);

int main(){ 
	menu(); 

	clearStack(flavorStack);
	clearQueue(idQueue);

	clearLine(2);
	return 0; 
} 

void menu(){ 
	int op = 0; 
	while(1){ 
		printf("------MENU------\n");
		printf("Options:\n1 - Produce meal boxes\n2 - Distribute meal boxes\n3 - Close system\nChoice: "); 
		scanf("%d", &op); 
		getchar(); 
		switch(op){ 
			case 1:
				clearLine(1);
				printf("------PRODUCE MEAL BOXES------\n");
				produce();
				break;
			case 2:
				clearLine(1);
				int verify = emptyStack(flavorStack);
				if(verify == 1){ //No meal boxes avalable
					printf("There is no boxes yet\n");
					exit(1);
				}
				printf("------DISTRIBUTE MEAL BOXES------\n");
				distribute(0);
				break;
			case 3 : 
				exit(1);
				break;
			default:
				printf("Invalid option\n\n");
				break;
		}
	}

}

int produce(){
	char str[SIZE_FLAVORS], *flavorOptions[SIZE_FLAVORS]; 
	int count=0, guess=0;

	flavorStack = createStack();

	printf("Total of flavors: ");
	scanf("%d", &count);
	getchar(); 
	for(int i=0; i<count; i++){
		printf("Flavor %d: ", i+1);
		fgets(str, sizeof(str), stdin);
		str[strcspn(str, "\n")] = '\0';
		removeSpaces(str);
		longString(strlen(str), SIZE_FLAVORS);

		flavorOptions[i] = (char*) malloc(strlen(str)+1);
		strcpy(flavorOptions[i], str);
	}
	
	printf("Total production: ");
	scanf("%d", &guess);
	getchar();

	for(int i=0; i<guess; ++i){ //guess determines the size of flavorStack
		insertItemStack(flavorStack, flavorOptions[i%count]);	
	}

	printStack(flavorStack);
	printf("%d\n", stackSize(flavorStack));

	clearLine(1);

	return guess;
}

void distribute(int guess){
	FILE *file1 = fopen("logMealBoxes.txt", "w");
	verifyFile(file1, "distribute()", "w");

	srand(time(NULL));
	int jocker=200;
	int quantStudents = rand()%jocker;

	idQueue = createQueue();

	for(int i=0; i<quantStudents; i++){ //quantStudents determines the size of idQueue
		char *id = generateId();
		insertItemQueue(idQueue, id);
		free(id);
	}	
	
	printQueue(idQueue);
	/*
	if(guess < quantStudents){
		for(int i=0; i<quantStudents; i++){
			fprintf(file1, "%s -> %s\n", idQueue->item, flavorStack->item);
		}
	}*/

	fclose(file1);
	clearLine(2);
}

char *generateId(){
	char *id = (char*) malloc(10);
	if(id == NULL){
		perror("Fail to allocate memory for string in generateId()");		
		exit(1);
	}
	char aux[10];

	for(int j=0; j<9; j++)
		aux[j] = (rand()%10)  + '0';

	id[9] = '\0';

	strcpy(id, aux);

	return id;
}
 
void clearLine(int q){ 
	for(int i=0; i<q; i++)
		printf("\n");
}

void longString(long int len, int SIZE){
	if(len >= SIZE){
		printf("Too long string!");
		clearLine(2);
		exit(1);
	}
}

void clearScreen(){ system("cls || clear"); }

void removeSpaces(char *s){
	int nonSpaceCount = 0;

	for(int i=0; s[i]!='\0'; i++){
		if(!isspace((unsigned char) s[i])){
			s[nonSpaceCount] = s[i];
			nonSpaceCount++;
		}
	}
	s[nonSpaceCount] = '\0';
}

void verifyFile(FILE *file, char *whichFunction, char *whichOption){
	if(!file){
		printf("Fail to create file in %s in '%s' option\n", whichFunction, whichOption);
		perror("Error");
		exit(1);
	}
}
