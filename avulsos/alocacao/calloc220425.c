#include <stdlib.h>
#include <stdio.h>

int main(){
    int* v;

    v = (int *)calloc(5, sizeof(int));

    for(int i=0; i<5; i++){
        printf("%d ", v[i]);
    }

    v = realloc(v, 3*sizeof(int));

    printf("\n\n");
    int count=0;
    for(int i=4; i<7; i++){
        v[count] = i;
        count++;
    }
    for(int i=0; i<3; i++){
        printf("%d ", v[i]);
    }

    free(v);

    printf("\n");
    return 0;
}