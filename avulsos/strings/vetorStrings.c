#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char s[10];
	char* ans[10];

	for(int j=0; j<10; j++){
		fgets(s, sizeof(s), stdin);
		s[strcspn(s, "\n")] = '\0';

		ans[j] = malloc(strlen(s)+1);
		strcpy(ans[j], s);
	}

	for(int i=0; i<10; i++){
		printf("%s ", ans[i]);
		free(ans[i]);
	}


	printf("\n");
	return 0;
}
