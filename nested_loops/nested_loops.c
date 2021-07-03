#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define NUM_ROWS	5
#define FIRST_CHAR	'A'
#define LAST_CHAR	'K'

int main() {
	int r;	// row loop
	int c;	// character loop

	// 예제 1
	for (r = 0; r < NUM_ROWS; ++r) {					// outer row loop
		for (c = FIRST_CHAR; c <= LAST_CHAR; ++c) {		// inner character loop
			printf("%c ", c);
		}
		printf("\n");
	}
	printf("\n");


	// 예제 2
	for (r = 0; r < 10; ++r) {
		for (c = FIRST_CHAR;c <= FIRST_CHAR + r; ++c) {
			printf("%c ", c);
		}
		printf("\n");
	}
	printf("\n");


	// 예제 3
	for (r = 0; r < 12; ++r) {
		for (c = FIRST_CHAR + r;c <= FIRST_CHAR + 12; ++c) {
			printf("%c ", c);
		}
		printf("\n");
	}


	return 0;
}