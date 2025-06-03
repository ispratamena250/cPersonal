#include <stdio.h>

int main(){
	char s[10], aux1, aux2;

	scanf("%s", s);

	printf("\n");
	for(int i=0; i<10; i++){
		if(i == 0){ aux1 = s[i]; }
		if(i == 1){ aux2 = s[i];  }
		if(i == 8 && s[i] == 'P'){
			int z1 = aux1 - '0';
			int z2 = aux2 - '0';
			z1 *= 10;
			int ans = z1 + z2;
			if(ans <= 11){
				printf("%d", ans+12);
			}else if(ans == 12){
				printf("00");
			}
		}
	}

	for(int i=0; i<10; i++){
		if(i > 1 && i < 8){ printf("%c", s[i]);  }
	}

	printf("\n");
	return 0;
}

