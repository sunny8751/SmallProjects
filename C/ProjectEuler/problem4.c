#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int isPalindrome (int n) {
	char string [(int) log10(n) + 1];
	sprintf(string, "%d", n);
	for (int i = 0; i < sizeof (string) / sizeof (char); i ++) {
		if (string[i] != string[sizeof (string) / sizeof (char) - i - 1]) {
			return 0;
		}
	}
	return 1;
}

int main() {
	// get all possible palindromes that are made from product of 3 digit numbers
	int* possible = (int *) malloc (sizeof(int) * 100);
	int index = 0;
	int size = 100;
	for (int i = 999; i >= 100; i --) {
		for (int j = 999; j >= 100; j --) {
			if (isPalindrome(i * j)) {
				possible[index++] = i * j;
				if (index == size) {
					possible = (int *) realloc (possible, size * 2 * sizeof(int));
				}
			}
		}
	}
	// answer is the maximum of the palindromes
	int answer = -1;
	for (int i = 0; i < index; i ++) {
		if (possible[i] > answer) {
			answer = possible[i];
		}
	}
	//print the palindrome
	printf("%d\n", answer);
	return 0;
}
