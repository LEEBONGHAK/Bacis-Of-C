﻿#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>		// pow()
#include <string.h>		// strlen()
#include <stdlib.h>		// exit()
#include <stdbool.h>

unsigned char to_decimal(const char bi[]);
void print_binary(const unsigned char num);

int main() {
	/*
		Regular Logical Operators : &&, ||, and !
	
		bool have_apple = true;
		bool like_apple = true;
		if (have_apple && like_apple) {
			eat_apple();
		}
	*/

	/*
		Bitwise Logical Operators : 
		- Bitwise NOT				~
		- Bitwise AND				&
		- Bitwise OR				|
		- Bitwise EXCLUSIVE OR		^		 
	*/
	unsigned char a = 6;
	unsigned char b = 5;

	printf("%hhu\n", a);
	print_binary(a);

	printf("%hhu\n", b);
	print_binary(b);

	printf("%hhu\n", a & b);
	print_binary(a & b);

	printf("%hhu\n", a | b);
	print_binary(a | b);

	printf("%hhu\n", a ^ b);
	print_binary(a ^ b);

	printf("%hhu\n", ~a);
	print_binary(~a);


	return 0;
}


unsigned char to_decimal(const char bi[]) {
	const size_t bits = strlen(bi);
	unsigned char result = 0;

	for (size_t i = 0; i < bits; i++) {
		if (bi[i] == '1') {
			result += (int)pow(2, bits - 1 - i);
		}
		else if (bi[i] != '0') {
			printf("Wrong character : %c\n", bi[i]);
			exit(1);
		}
	}

	return result;
}

void print_binary(const unsigned char num) {
	printf("Decimal\t%d\t== Binary ", num);

	const size_t bits = sizeof(num) * 8;
	for (size_t i = 0; i < bits; i++) {
		const unsigned char mask = (unsigned char)pow((double)2, (double)(bits - 1 - i));
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