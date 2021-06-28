#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int main() {
	unsigned int i = 0;

	// 자료형의 사이즈를 알려줌(bit로)
	printf("%u\n", sizeof(unsigned int));
	printf("%u\n", sizeof(i));

	// overflow : 메모리 범위를 넘어가는 값을 가졌을 때 표현
	// ex) unsigned int i = 0b1000000000000000000000000; -> overflow 발생 / 0 출력 후 error 표시
	// 0b : 2진수를 나타내주는 표시, 표준은 아님 -> 2진수 직접 입력

	// unsigned int u = UINT_MAX; -> maximum number of unsigned int = 2^32-1
	// signed int x = INT_MAX; maximum number of unsigned int = 2^31-1
	// unsigned int u = 0; -> minimum number of unsigned int = 0
	// signed int x = INT_MIN; minimum number of unsigned int = -2^31


	unsigned int i_overflow = UINT_MAX + 1;

	// 1111 + 1 = 10000 -> 만약 메모리가 4 bit라면 메모리를 초과하는 앞에 '1'은 저장되지 않음(overflow)
	// 0000 - 1 = 1111 -> 마치 앞에 1이 존재하는 것처럼 계산됨

	// i_overflow to binary representation
	char buffer[33];
	_itoa(i, buffer, 2);

	// print decimal and binary
	printf("decimal: %u\n", i_overflow);
	printf("binary: %s\n", buffer);

	return 0;
}