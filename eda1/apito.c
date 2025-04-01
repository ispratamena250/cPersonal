#include <stdio.h>
#include <stdlib.h>

int main(){
	char s[20] = "Aqui vai um apito\a";

	printf("%s\n", s);

	system("./apito.x");

	printf("\n");
	return 0;
}
