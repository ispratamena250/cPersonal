#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include "pilhaStringsHeader.h"
#include "filaStringsHeader.h"

#define SIZE_FLAVORS 100 
Stack *flavorStack;
Queue *idQueue;
int guess=0;
float mealBoxValue=0;

//Prototypes 
void menu(); 
void produce(); 
int distribute(); 
char *generateId(); 
void breakLine(int q); 
void longString(long int tam, int TAM); 
void removeSpaces(char *s);
void verifyFile(FILE *file, char *whichFunction, char *whichOption);

int main(){ 
	flavorStack = createStack();
	idQueue = createQueue();

	menu(); 

	clearStack(flavorStack);
	clearQueue(idQueue);

	return 0; 
} 

void menu(){ 
	int op=0, verify=0, flag=1; 
	while(1){ 
		printf("------MENU------\n");
		printf("Options:\n1 - Produce meal boxes\n2 - Distribute meal boxes\n3 - Close system\nChoice: "); 
		scanf("%d", &op); 
		getchar(); 
		switch(op){ 
			case 1:
				breakLine(1);
				verify = emptyStack(flavorStack);
				if(verify == 1){
					printf("------PRODUCE MEAL BOXES------\n");
					produce();
				}else{
					printf("You already produced it!\n");
				}
				break;
			case 2:
				breakLine(1);
				verify = emptyStack(flavorStack);
				if(verify == 0){
					if(flag == 1){
						printf("------DISTRIBUTE MEAL BOXES------\nCheckout the log file!\n");
						flag = distribute();
					}else if(flag == 0){
						printf("You already destributed it!\n");
					}
				}else{
					printf("There is no boxes yet!\n");
				}
				break;
			case 3 : 
				exit(1);
				break;
			default:
				printf("Invalid option\n\n");
				break;
		}
	}
	breakLine(2);
}

void produce(){
	char str[SIZE_FLAVORS], *flavorOptions[SIZE_FLAVORS]; 
	int count=0;

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
	printf("Meal box value: ");
	scanf("%f", &mealBoxValue);
	
	printf("Total production: ");
	scanf("%d", &guess);

	for(int i=0; i<guess; ++i) //guess determines the size of flavorStack
		insertItemStack(flavorStack, flavorOptions[i%count]);	

	breakLine(1);
}

int distribute(){
	FILE *file1 = fopen("logMealBoxes.txt", "w");
	verifyFile(file1, "distribute()", "w");

	srand(time(NULL));
	int jocker=200;
	int quantStudents = rand()%jocker;
	float sue = (float)(rand()%(jocker*jocker)/jocker);
	int suePrejudice=0, mealBoxPrejudice=0, profit=0, flag=0;

	for(int i=0; i<quantStudents; i++){ //quantStudents determines the size of idQueue
		char *id = generateId();
		insertItemQueue(idQueue, id);
		free(id);
	}	

	if(guess > quantStudents){
		for(int i=0; i<guess; i++){
			if(i < quantStudents){
				char *itemStack = getStackItemAt(flavorStack, i);
				char *itemQueue = getQueueItemAt(idQueue, i);
				fprintf(file1, "%s -> %s\n", itemStack, itemQueue);
				profit++;
			}else{
				char *itemStack = getStackItemAt(flavorStack, i);
				fprintf(file1, "%s -> prejuizo\n", itemStack);
				mealBoxPrejudice++;
			}
		}
	}else if(guess < quantStudents){
		for(int i=0; i<quantStudents; i++){
			if(i < guess){
				char *itemStack = getStackItemAt(flavorStack, i);
				char *itemQueue = getQueueItemAt(idQueue, i);
				fprintf(file1, "%s -> %s\n", itemStack, itemQueue);
				profit++;
			}else{
				char *itemQueue = getQueueItemAt(idQueue, i);
				fprintf(file1, "%s -> aguarde o processo\n", itemQueue);
				suePrejudice++;
			}
		}
	}else{
		for(int i=0; i<guess; i++){
			char *itemStack = getStackItemAt(flavorStack, i);
			char *itemQueue = getQueueItemAt(idQueue, i);
			fprintf(file1, "%s -> %s\n", itemStack, itemQueue);
			profit++;
		}
	}		

	fprintf(file1, "\nMeal box prejudice: $%.2f\nSue prejudice: $%.2f\nProfit: $%.2f\n", mealBoxValue*mealBoxPrejudice, sue*suePrejudice, mealBoxValue*profit);
	if((mealBoxValue*mealBoxPrejudice) + (sue*suePrejudice) > (mealBoxValue*profit)){
		fprintf(file1, "Faliu!!");
	}else{
		fprintf(file1, "Deu lucro!!");
	}

	fclose(file1);

	breakLine(1);
	
	return flag; //This is for checking if you already distributed the boxes
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
 
void breakLine(int q){ 
	for(int i=0; i<q; i++)
		printf("\n");
}

void longString(long int len, int SIZE){
	if(len >= SIZE){
		printf("Too long string!");
		breakLine(2);
		exit(1);
	}
}

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
