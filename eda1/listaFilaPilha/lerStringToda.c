#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char s[100];

	fgets(s, sizeof(s), stdin);

	s[strcspn(s, "\n")] = 0;

	printf("%s", s);

	printf("\n");
	return 0;
}
