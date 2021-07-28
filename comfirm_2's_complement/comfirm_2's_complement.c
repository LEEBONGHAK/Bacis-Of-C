#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>		// pow()
#include <string.h>		// strlen()
#include <stdlib.h>		// exit()

void print_binary(const unsigned char num);

int main() {
	/*
		Signed Integers

		- Sign-magnitude representation
		00000001 is 1 and 10000001 is -1
		00000000 is +0 and 10000000 is -0
		Two zeros +0 -0, from -127 to +127

		- One's complement method
		To reverse the sign, invert each bit.
		00000001 is 1 and 11111110 is -1.
		11111111 is -0 from -127 to +127

		- Two's complement method (commonly used in most systems)
		To reverse the sign, invert each bit and add 1.
		from -128 to +127
	*/

	print_binary(127);
	print_binary(-127);
	print_binary(~127);
	print_binary(~127 + 1);
	printf("\n");


	print_binary(12);
	print_binary(-12);
	print_binary(~12);
	print_binary(~12 + 1);
	printf("\n");


	print_binary(-7);
	print_binary(7);
	print_binary(~-7);
	print_binary(~-7 + 1);
	printf("\n");


	return 0;
}

void print_binary(const char num) {
	printf("Decimal\t%d\t== Binary ", num);

	const size_t bits = sizeof(num) * 8;
	for (size_t i = 0; i < bits; i++) {
		const char mask = (unsigned char)pow((double)2, (double)(bits - 1 - i));
		//unsigned char mask = pow(2, (bits - 1 - i));		// Warning but, Ok

		if ((num & mask) == mask) {
			printf("%d", 1);
		}
		else {
			printf("%d", 0);
		}
	}
	printf("\n");
}