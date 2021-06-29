#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>

int main() {
	printf("%u\n", sizeof(_Bool)); // 1 byte (자료형이 가질 수 있는 최소 메모리)

	_Bool b1;
	b1 = 0; // false
	printf("%d\n", b1);
	b1 = 1; // true
	printf("%d\n", b1);

	bool b2, b3;
	b2 = true;
	b3 = false;

	printf("%d %d\n", b2, b3);


	return 0;
}