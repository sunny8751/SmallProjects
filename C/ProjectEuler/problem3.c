#include <stdio.h>

int main() {
	long n = 600851475143;
	for (long i = 3; i < n; i+= 2) {
		while (n % i == 0) {
			n /= i;
		}
	}
	printf ("%ld\n", n);
	return 0;
}
