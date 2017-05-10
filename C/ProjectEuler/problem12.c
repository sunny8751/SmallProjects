#include <stdio.h>

int getTriangleNumber (int n) {
	if (n == 1) {
		return 1;
	}
	return n + getTriangleNumber (n - 1);
}

int main() {
	int n = 0;
	int tn = 1;
	for (int i = 1; n <= 500; i ++) {
		n = 0;
		tn = getTriangleNumber (i);
		for (int j = 1; j*j <= tn; j++) {
			if (tn % j == 0) {
				n += 2;
			}
		}
	}
	printf ("%d\n", tn);
	return 0;
}
