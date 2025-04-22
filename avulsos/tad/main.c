#include <stdio.h>
#include "matematica.h"

int main(){
    int a = 7, b =3;

    int sm = soma(a, b);
    int sb = sub(a, b);

    printf("%d\n%d", sm, sb);

    printf("\n");
    return 0;
}