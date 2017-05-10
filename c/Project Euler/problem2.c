#include <stdio.h>

int main() {
	int sum = 0;
	int term1 = 1;
	int term2 = 1;
	int term3;
	while (term3 <= 4e6) {
		term3 = term1 + term2;
		if (term3 % 2 == 0) {
			sum += term3;
		}
		term1 = term2;
		term2 = term3;
	}
	printf ("%d", sum);
	return 0;
}
