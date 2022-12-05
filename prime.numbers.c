#include<stdio.h>
#include<math.h>
#define SIZE 1200

int *get_primes(int *primes) {

	int i = 0;
	primes[i] = 2;
	i++;

	int j = 0;
	int number = 3;

	while(1) {
		if (i == SIZE) {
			break;	
		}
		
		if (sqrt(number) < (double) primes[j]) { // a prime
			primes[i] = number;
			i++;
			number++;
			j = 0;
			continue;
		}

		if (number % primes[j] == 0) { // not a prime
			number++;
			j = 0;
			continue;
		}
		j++;
	}

	return primes;
}

int main() {
	int *p;
	int primes[SIZE];
	p = get_primes(primes);
	for (int i=0; i<SIZE; i++) {
                printf("Prime number: %d\n", p[i]);
        }
	return 0;
}
