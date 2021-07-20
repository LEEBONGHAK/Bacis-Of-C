#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

static unsigned int my_next = 1;

int my_rand() {
	my_next = my_next * 1103515245 + 1234;
	my_next = (unsigned int)(my_next / 65536) % 32768;

	return (int)my_next;
}

void my_srand(unsigned int seed) {
	my_next = seed;
}