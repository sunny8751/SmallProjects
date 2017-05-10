#include <stdio.h>

int main() {
	int prime, primeCount = 0;

	for (int i = 2; primeCount < 10001; i++) {
		//test if i is prime
		int isPrime = 1;
		for (int j = 2; j < i; j++) {
			if (i % j == 0) {
				isPrime = 0;
			}
		}
		if (isPrime) {
			prime = i;
			primeCount ++;
		}
	}

	printf ("%d\n", prime);
	return 0;
}
