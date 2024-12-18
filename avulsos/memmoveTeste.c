#include <stdio.h>
#include <string.h>

int main(){
	char s1[10] = "palavra1";
	char s2[20] = "palavra2";

	puts(s1);
	puts(s2);
	memmove(s1, s2, sizeof(s1));
	puts(s1);
	puts(s2);

	return 0;
}
