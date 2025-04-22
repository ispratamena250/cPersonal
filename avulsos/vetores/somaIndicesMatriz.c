#include <stdio.h>

int main(){
	for(int i=0; i<6; i++)
		for(int j=0; j<6; j++)
			printf("%d ", i+j);

	printf("\n");
	return 0;
}
