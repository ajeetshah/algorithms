#include<stdio.h>
#define SIZE 4

int findPair(int A[], int sum, int size, int *p1, int *p2) {

	int pairFound = 0;
	int i, j;

	for (i=0; i<size; i++) {
		for(j=0; j<size; j++) {
			if (A[i] + A[j] == sum){
				*p1 = i;
				*p2 = j;
				pairFound = 1;
				return pairFound;
			}
		}
	}

	return pairFound;
}

int main() {

	int A[SIZE] = {2, 6, 3, 8};
	int sum;
	int p1 = 0;
	int p2 = 0;

	printf("Enter the sum: ");
	scanf("%d", &sum);
	
	int pairFound = findPair(A, sum, SIZE, &p1, &p2);

	if (pairFound) {
		printf("%d and %d\n", A[p1], A[p2]);
	}
	else {
		printf("No such pair was found\n");
	}
	return 0;
}

