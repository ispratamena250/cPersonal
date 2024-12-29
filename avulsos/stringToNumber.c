#include <stdio.h>
#include <string.h>

#define TAM 4

int main(){
	char s1[TAM] = "133";
	//printf("%s\n", s1 - '0');
	for(int i=0; i<TAM-1; i++){
		printf("%daqui%d ", s1[i] - '0', s1[i]);
	}	

  printf("\n");
  for(int i=0; i<TAM-1; i++){
    printf("%d", s1[i] - '0');
  }

  printf("\n");
	return 0;
}
