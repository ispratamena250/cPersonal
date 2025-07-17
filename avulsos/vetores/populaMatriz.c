#include <stdio.h>

// Function to populate an existing matrix
void populateMatrix(int rows, int cols, int matrix[rows][cols]) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			matrix[i][j] = i * cols + j + 1;
		}
	}
}

// Example usage
int main() {
	int rows = 3;
	int cols = 4;

	// Declare a static matrix
	int myMatrix[rows][cols];

	// Populate the matrix using the function
	populateMatrix(rows, cols, myMatrix);

	// Print the matrix
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			printf("%d ", myMatrix[i][j]);
		}
		printf("\n");
	}

	return 0;
}
