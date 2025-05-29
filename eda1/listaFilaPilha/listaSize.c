#include <stdio.h>
#include <stdlib.h>

typedef struct __attribute__((packed)) s{
	int z;
	char c;
}S;

int main(){
	printf("%lu\n", sizeof(S));

	printf("\n");
	return 0;
}
