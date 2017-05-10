#include <stdio.h>

int main () {
	int threshold = 1000;
	int sum = 0;
	for (int i = 0; i < threshold; i++) {
		if (i % 3 == 0 || i % 5 == 0) {
			sum += i;
		}
	}
	printf ("%d", sum);
	return 0;
}
