#include<stdio.h>
#define N 10
/* the #define directive allows the definition of macros within your source code. These macro definitions allow constant values to be declared for use throughout your code. ... You generally use this syntax when creating constants that represent numbers, strings or expressions. */ 
void swap(int A[], int i, int j) {
	int t;
	t = A[i];
	A[i] = A[j];
	A[j] = t;
}
// we are shorthing an array either in assending or in descendig order//
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
/* the function which we have made above we can use that here */ 
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
