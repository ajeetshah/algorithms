#include<stdio.h>
#define N 15

void findNumOdd(int A[], int n) {
	int i;
	int j;
	int countZero = 0;
	int operations = 0;
	int el;
	int start = 0;

	for(j=0; j<n; j++){
	while(A[start] == 0) {
		start++;
	}

	el = A[start];
	operations -= el;

	for (i=start; i<n; i++) {
		if (A[i] != 0) {
			A[i] -= el;
			if (A[i] == 0) {
				countZero++;
			}
		}
	}

	if (countZero % 2 != 0) {
		return (operations < 0 ? -operations : operations);
	}
	}
}

int main() {
	int A[N] = {
		12, 12, 2, 3, 9,
		2, 3, 3, 3, 9,
		9, 10, 10, 12, 12
	};
	findNumOdd(A, N);
	return 0;
}

