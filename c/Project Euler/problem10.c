#include <stdio.h>

int main() {
	long sum = 0;
	
	for (long i = 2; i < 2e6; i ++){
		//test if prime
		int isPrime = 1;
		for (long j = 2; j * j <= i; j ++) {
			if (i % j == 0) {
				isPrime = 0;
			}
		}
		if (isPrime) {
			sum += i;
		}
	}

	printf ("%ld\n", sum);
	return 0;
}
