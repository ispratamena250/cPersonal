#include <stdio.h>
#include <string.h>

int main(){
	int count=0;
	char s[100000];

	scanf("%s", s);
	//printf("%ld\n", sizeof(s)); //100000
	//printf("%zu\n", strlen(s)); //22 para o caso da string 'saveChangesInTheEditor'

	for(int i=0; i<strlen(s); i++)
		if(s[i] >= 'A' && s[i] <= 'Z')
			count++;

	printf("%d\n", count+1);

	printf("\n");
	return 0;
}
