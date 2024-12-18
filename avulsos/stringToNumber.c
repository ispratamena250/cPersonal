#include <stdio.h>
#include <string.h>

int main(){
	char s1[2] = "2";
	//printf("%s\n", s1 - '0');
	for(int i=0; i<2; i++){
		printf("%d\n", s1[i] - '0');
	}	

	return 0;
}
