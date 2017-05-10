#include <stdio.h>

int evenlyDivisible (int n) {
	// evenly divisible from 1 to 20
	for (int i = 1; i <= 20; i ++) {
		if (n % i != 0) {
			return 0;
		}
	}
	return 1;
}

int main() {
	int n;
	for (n = 19; !evenlyDivisible (n); n += 19);
	printf ("%d\n", n);
	return 0;
}
