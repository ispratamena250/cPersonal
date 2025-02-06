/*
 * C program to implement the elliptic curve cryptography
 * Isaac Menezes Pereira, 190088885 - feb, 2025
 *
 * Compile: gcc -Wall elipticas_IsaacMenezes.c -o elipticas_IsaacMenezes.x 
 * Run: ./elipticas_IsaacMenezes.x a b p
 * */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Signatures
void generatingPoints(int a, int b, int p, int n);
void choosingPoints(int n);

int main(int argc, char *argv[4]){
  if(argc != 4){
    printf("Error! Run $ ./elipticas_IsaacMenezes.x a b p\n");
    printf("Thes arguments satisfy: y^2 = x^3 + ax + b (mod p)\n");
    exit(1);
  }

  int a = atoi(argv[1]), 
      b = atoi(argv[2]),
      p = atoi(argv[3]),
      n = 0;

  generatingPoints(a, b, p, n);

  return 0;
}

//Generating the points
void generatingPoints(int a, int b, int p, int n){
  //Creating first file
  FILE *file1 = fopen("pointsElliptics.dat", "w");
  if(!file1){
    printf("Error on openning pointsElliptics.dat in 'w'\n");
    exit(1);
  }

  //Generating the points with a limit of the quantitie 
  for(int x=0; x<p; x++){
    for(int y=0; y<p; y++){
      if(y*y % p == (x*x*x + a*x + b) % p){
        n++;
        fprintf(file1, "%d\t%d\n", x, y);
        if(n > 1000){
          break;
        }
      }
    }
  }

  fclose(file1);

  system("open pointsElliptics.dat");

  choosingPoints(n); 
} 

//Choosing the points for the finding order algorithm
void choosingPoints(int n){
  srand(time(NULL));
  char buffer[100];

  FILE *file2 = fopen("pointsElliptics.dat", "r");
  if(!file2){
    printf("Error on openning pointsElliptics.dat in 'r'\n");
    exit(1);
  }
  FILE *file3 = fopen("choosedPoints_ellipticCurve.dat", "w");
  if(!file3){
    printf("Error on openning choosedPoints_ellipticCurve.dat in 'w'\n");
    exit(1);
  }

  //Checking the number of lines in file2
  int totalLines=0;
  while(fgets(buffer, sizeof(buffer), file2)){
    totalLines++;
  }
  rewind(file2);

  //Creating the vector with a specific size depending on the number of lines in file2
  int tamVetor;
  if(n > 100){
    tamVetor = 100;
  }else{
    tamVetor = n;
  }
  int v_random[tamVetor];
  
  //Assigning random values to the vector depending on its size and the number of lines in file2
  for(int i=0; i<tamVetor; i++){
    int aux = rand() % n;
    v_random[i] = aux;
  }  
  
  //Printing the specific line in file2 depending on the index of the vector
  for(int i=0; i<tamVetor; i++){
    int desiredLine = v_random[i];
    rewind(file2); //Comes back to tho first line of the file
    int currentLine = 1;
    while(fgets(buffer, sizeof(buffer), file2)){
      if(currentLine == desiredLine){
          //printf("%d -> %s", currentLine, buffer); //Just for checking
          fprintf(file3, "%s", buffer);
          break;
      }
      currentLine++;
    }
  } 

  fclose(file2);
  fclose(file3);

  system("open choosedPoints_ellipticCurve.dat");
}
