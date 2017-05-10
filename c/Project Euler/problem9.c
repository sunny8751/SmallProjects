#include <stdio.h>

int main() {
	int n;
	
	for (int i = 1; i < 999; i++) {
		for (int j = 1; j < 1000 - i; j++) {
			int k = 1000 - i - j;
			//test to see if i, j, k is a pythagorean triplet
			int n1, n2;
			if (i > j && i > k) {
				n1 = i * i;
				n2 = j * j + k * k;
			} else if (j > i && j > k) {
				n1 = j * j;
				n2 = i * i + k * k;
			} else {
				n1 = k * k;
				n2 = i * i + j * j;
			}
			if (n1 == n2) {
				printf ("%d\n", i * j * k);
				return 0;
			}
		}
	}

	return 0;
}
