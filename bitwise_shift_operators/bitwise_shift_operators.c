#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void int_binary(const int num);

int main() {
	/*
		Bitwise Shift Operators - 비트 이동(쉬프트) 연산자
		
		- Left shift
		number << n : multiply number by 2^n - 항상 그런건 아님
		2진수에서 n번만큼 왼쪽으로 이동

		- Right shift
		number >> n : divided by 2^n (for non-negative numbers) - 항상 그런건 아님
		2진수에서 n번만큼 오른쪽으로 이동
	*/

	// 8 bit integer cases
	//									   76543210		   76543210		   76543210
	printf("%hhd\n", 1 << 3);			// 00000001 ->	00000001???		-> 00001000
	printf("%hhd\n\n", 8 >> 1);			// 00001000 ->	   ?00001000	-> 00000100


	printf("%hhd\n", -119 >> 3);		// 10001001 ->	   ???10001001	-> 11110001 (-15)
	//printf("%hhd\n", -119 / 8);		// -14
	printf("%hhd\n\n", 137 >> 3);		// 10001001 ->	   ???10001001	-> 00010001 (17)
	//printf("%hhd\n", 137 / 8);		// 17


	printf("%hhd\n", -119 << 4);		// 10001001 -> 10001001????		-> 10001000 (-112)
	printf("%hhd\n\n", 137 << 4);		// 10001001 -> 10001001????		-> 10001000 (144)

	//Note: the signed result is machine dependent

	

	int a = 1;
	a <<= 3;
	a >>= 2;

	printf("Unsigned int %u\n", 0xffffffff);
	printf("Signed int %d\n", 0xffffffff);
	int_binary(0xffffffff);
	printf("Right shift by 3\n");
	int_binary((signed)0xffffffff >> 3);
	int_binary((unsigned)0xffffffff >> 3);

	printf("\nUnsigned int %u\n", 0x00ffffff);
	printf("Signed int %d\n", 0x00ffffff);
	int_binary(0x00ffffff);
	printf("Right shift by 3\n");
	int_binary((signed)0x00ffffff >> 3);
	int_binary((unsigned)0x00ffffff >> 3);


	return 0;
}

void int_binary(const int num) {
	printf("Decimal\t%d\t== Binary ", num);

	const size_t bits = sizeof(num) * CHAR_BIT;
	for (size_t i = 0; i < bits; ++i) {
		const int mask = 1 << (bits - 1 - i);
		
		if ((num & mask) == mask) {
			printf("%d", 1);
		}
		else {
			printf("%d", 0);
		}
	}
	printf("\n");
}