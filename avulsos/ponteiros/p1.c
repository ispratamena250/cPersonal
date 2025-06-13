#include <stdio.h>

int main(){
	int a = 10;
	int b = 20;

	int *x = &a;
	int *y = &b;

	printf("%p\n%d\n%p\n%p\n", &a, b, x, y);

	printf("\n");
	return 0;
}
