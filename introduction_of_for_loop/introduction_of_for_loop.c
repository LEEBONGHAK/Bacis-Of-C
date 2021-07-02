#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	int i = 1;

	// Indefinite loop (while) vs. Counting loop (for)
	while (i <= 10) {
		printf("%d\n", i);
		i++;
	}


	/*
		Counting Loop
		1. Counter initialization
		2. Counter check
		3. Counter change
	*/

	for (i = 1; i <= 10; i++) {
		printf("%d\n", i);
	}

	return 0;
}