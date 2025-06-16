#include <stdio.h>

int main(){
	int a = 12;
	int *b = &a;
	int *c = NULL;
	int x = 10;
	int *y;
	y = &x;
	*y = 15;

	printf("a = %d\n&a = %pt\nb = %pt\n&b = %pt\nc = %p\n&c = %p", a, &a, b, &b, c, &c);
	printf("\nx = %d\n&x = %p\ny = %p\n&y = %p\nx = %d", x, &x, y, &y, x);

	printf("\n");
	return 0;
}
