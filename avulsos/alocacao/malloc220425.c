#include <stdio.h>
#include <stdlib.h>

int main(){
    int* v;

    v = (int *)malloc(5 * sizeof(int));

    for(int i=0; i<5; i++){
        printf("%d ", v[i]);
    }

    free(v);

    printf("\n");
    return 0;
}