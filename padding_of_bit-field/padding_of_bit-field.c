﻿#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <limits.h>		// CHAR_BIT
#include <stdbool.h>

void char_to_binary(unsigned char uc);
void print_binary(char* data, int bytes);		//Note: extended for any sizes

int main() {
	struct {
		bool option1 : 1;
		//bool		 : 0;
		bool option2 : 1;
		unsigned long long option3 : 1;
	} bbf;

	memset((char*)&bbf, 0xff, sizeof(bbf));
	print_binary((char*)&bbf, sizeof(bbf));
	bbf.option1 = 0;
	bbf.option2 = 0;
	bbf.option3 = 0;
	print_binary((char*)&bbf, sizeof(bbf));

	printf("Size is %zu bytes\n\n", sizeof(bbf));



	struct {
		unsigned short option1 : 8;
		unsigned short option2 : 7;
		//unsigned short : 0;
		unsigned short option3 : 1;
	} usbf;
	
	printf("Size is %zu bytes\n\n", sizeof(usbf));



	struct {
		unsigned int option1 : 1;
		//unsigned int : 0;
		unsigned int option2 : 1;
		bool option3 : 1;
	} uibf;

	printf("Size is %zu bytes\n\n", sizeof(uibf));


	return 0;
}

void char_to_binary(unsigned char uc) {
	const int bits = sizeof(unsigned char) * CHAR_BIT;
	for (int i = bits - 1; i >= 0; i--) {
		printf("%d", (uc >> i) & 1);
	}
}

void print_binary(char* data, int bytes) {
	for (int i = 0; i < bytes; ++i) {
		char_to_binary(data[bytes - 1 - i]);
	}
	printf("\n");
}