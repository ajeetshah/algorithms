#include<stdio.h>
#define SIZE 1200

int main() {
	int primes[SIZE] = {0};

	int i = 0;
	primes[i] = 2;
	primes[++i] = 3;

	while(1) {
		printf("Inside while loop\n");
		if (i == SIZE) {
			break;	
		}
		// 
		//

		i++;
	}

	for (int i=0; i<SIZE; i++) {
		printf("Prime number: %d, ", primes[i]);
	}

	return 0;
}

