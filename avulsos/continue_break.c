#include <stdio.h>

int main(){
	for(int i=0; i<5; i++){
		if(i==3)
			break;

		printf("%d ", i);
	}
	printf("\n");

	for(int i=0; i<5; i++){
		if(i==3)
			continue;

		printf("%d ", i);
	}
	
	printf("\n");
	return 0;
}
