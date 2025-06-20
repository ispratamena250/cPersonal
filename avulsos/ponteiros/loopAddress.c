#include <stdio.h>

int main(){
	int v[10];

	for(int i=0; i<10; i++){
		v[i] = i;
	}

	for(int i=0; i<10; i++){
		printf("%p\n", &v[i]);
	}

	printf("\n");
	return 0;
}
