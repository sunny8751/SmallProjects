#include <stdio.h>
#include <stdlib.h>

char* reverse(char*);

int main() {
	char* s;
	scanf ("%s", s);
	char* r = reverse(s);
	printf("%s\n", r);
	free (r);
	return 0;
}

char* reverse (char* s) {
	int count;
	int c;
	for (count = 0; (c = s[count]) != '\0'; count++);
	char* reversed = (char*) malloc (count + 1);
	for (int i = 0; i < count; i++) {
		reversed[i] = s[count - i - 1];
	}
	reversed[count] = '\0';
	return reversed;
}
