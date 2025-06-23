#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include "pilhaStringsHeader.h"
#include "filaStringsHeader.h"
#define SIZE_FLAVORS 100 

//Prototypes 
void menu(); 
void produce(); 
void distribute(); 
char* generateId(); 
void clearLine(); 
void longString(long int tam, int TAM); 
void clearScreen(); 
void removeSpaces(char* s);

int main(){ 
	menu(); 

	clearLine();
	return 0; 
} 

void menu(){ 
	int op = 0; 
	while(1){ 
		printf("Options:\n1 - Produce lunchs\n2 - Distribute lunchs\n3 - Close system\nChoice: "); 
		scanf("%d", &op); 
		getchar(); 
		switch(op){ 
			case 1:
				clearScreen();
				produce();
				break;
			case 2:
				clearScreen();
				distribute();
				break;
			case 3 : 
				exit(1);
				break;
			default:
				clearScreen();
				printf("Invalid option\n\n");
				break;
		}
	}

}

void produce(){
	char flavors[SIZE_FLAVORS];
	int count = 0;

	Stack* s = createStack(); //Flavors stack
				  
	printf("Total of flavors: ");
	scanf("%d", &count);
	for(int i=0; i<count; i++){
		printf("Flavor %d: ", i+1);
		scanf("%s", flavors);
		removeSpaces(flavors);
		longString(strlen(flavors), SIZE_FLAVORS);
		insertItemStack(s, flavors);	
	}

	printStack(s); //@

	clearLine();
}

void distribute(){
	srand(time(NULL));

	Queue* q = createQueue();

	int jocker=200;
	int quantStudents = rand()%jocker;

	for(int i=0; i<quantStudents; i++){
		char* id = generateId();
		insertItemQueue(q, id);
		free(id);
	}	
	
	printQueue(q); //@

	clearLine();
}

char* generateId(){
	char* id = (char*) malloc(10);
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
 
void clearLine(){ printf("\n\n"); }

void longString(long int len, int SIZE){
	if(len >= SIZE){
		printf("Too long string!");
		clearLine();
		exit(1);
	}
}

void clearScreen(){ system("cls || clear"); }

void removeSpaces(char* s){
	int nonSpaceCount = 0;

	for(int i=0; s[i]!='\0'; i++){
		if(!isspace((unsigned char) s[i])){
			s[nonSpaceCount] = s[i];
			nonSpaceCount++;
		}
	}
	s[nonSpaceCount] = '\0';
}
