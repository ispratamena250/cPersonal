#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char num1[2] = "1";
	char num2[2] = "1";
	int len1 = strlen(num1);
	//int len2 = strlen(num2);
	int carry=0;

	for(int j=0; j<10; j++){
		for(int i = len1-1; i<=0; i--){
			int digit = (num1[i] - '0') + (num2[i] - '0') + carry;
			num1[i] = (digit % 10) + '0';
			carry = digit/10;
			printf("num1 %c\n", num1[i]);
		}
		if(carry){
			memmove(num1 + 1, num1, len1+1);
			num1[0] = carry + '0';
			printf("comCarry: %d\n", carry);
		}
	}

	return 0;
}
