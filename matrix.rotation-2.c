#include<stdio.h>
#include<stdlib.h>

void printA(int** A, int rows, int cols) {
        int i, j;
	for(i=0; i<rows; i++) {
                for(j=0; j<cols; j++){
                        printf("%d ", A[i][j]);
                }
                printf("\n");
        }
}

void inverse(int** A, int rows, int cols) {
	int i, j, t;
	for(i=0; i<rows/2; i++) {
		for(j=0; j<cols; j++) {
			t = A[i][j];
			A[i][j] = A[rows-i-1][j];
			A[rows-i-1][j] = t;
		}
	}
}

void transpose(int** A, int rows, int cols) {
	int i, j, t;
	for(i=0; i<rows; i++) {
		for(j=i; j<cols; j++){
			t = A[i][j];
			A[i][j] = A[j][i];
			A[j][i] = t;
		}
	}
}

int main() {
	int rows = 4;
	int cols = 4;
	int** A = (int**) malloc(rows * sizeof(int*));

	int i, j;
	for(i=0; i<=rows-1; i++) {
		A[i] = (int*) malloc(cols * sizeof(int));
	}

	int data = 1;
	for(i=0; i<=rows-1; i++) {
		for(j=0; j<=cols-1; j++){
    			A[i][j] = data++;
		}
	}

	printA(A, rows, cols);
	
	inverse(A, rows, cols);
	transpose(A, rows, cols);

	printA(A, rows, cols);
	return 0;
}
