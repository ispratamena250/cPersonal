#include <stdio.h>
#include <string.h>

int main(){
	char a[10], b[10];

	scanf("%s", a);
	scanf("%s", b);

	int ans = strcmp(a, b);
	printf("%d", ans);

	printf("\n");
	return 0;
}
