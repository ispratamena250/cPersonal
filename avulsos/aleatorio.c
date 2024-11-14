#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	//srand(time(100));
	int n;
	int superior=2000, inferior=100;

	n = rand() % (superior - inferior + 1) - inferior;

	printf("%d\n", n);

	return 0;
}
