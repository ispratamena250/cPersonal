#include <stdio.h>
#include <string.h>

#define MAX 10

int main(){
	int arr[MAX];

	memset(arr, 0, MAX*sizeof(arr[0]));

	for(int i=0; i<MAX; i++)
		printf("%d ", arr[i]);

	printf("\n");
	return 0;
}
