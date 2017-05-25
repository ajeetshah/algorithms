#include<stdio.h>
#define N 10

void swap(int A[], int i, int j) {
	int t;
	t = A[i];
	A[i] = A[j];
	A[j] = t;
}

void sortArray(int A[], int n) {
	int i, j;
	int min;

	for (i=0; i<n-1; i++) {
		min = i;
		for (j=i+1; j<n; j++) {
			if (A[min] > A[j]) {
				min = j;
			}
		}
		if (i!=min) { 
			swap(A, i, min);
		}
	}
}

int findMajority(int A[], int n, int *major) {
	int found = 0;
	int i;
	int c = 1;

	for (i=0; i<n-1; i++) {
		if (A[i] == A[i+1]) {
			c++;
			if (c > n/2) {
				*major = A[i];
				found = 1;
				return found;
			}
		}
		else {
			c = 1;
		}
	}

	return found;
}

int main() {
	int i;
	int A[N] = {
			9, 3, 9, 4, 9, 
			9, 5, 9, 9, 12
	};

	sortArray(A, N);

	for (i=0; i<N; i++) {
		printf("%d ", A[i]);
	}
	printf("\n");

	int major;
	int found = findMajority(A, N, &major);

	if (found) {
		printf("majority: %d\n", major);
	}
	else {
		printf("NONE");
	}

	return 0;
}



/*
 *
 * 1. O(sort) + n-1 comparisions
 * 2. 
 *
*/
