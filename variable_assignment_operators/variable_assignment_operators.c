#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	/*
		+=, -=, *=, /=, %=
	*/

	int i = 1024;
	
	i = i + 10;
	i += 10;

	i = i - 10;
	i -= 10;

	i = i * 10;
	i *= 10;

	i = i / 10;
	i /= 10;

	i = i % 4;
	i %= 4;

	i = i * (1 + 2);
	i *= 1 + 2;
	i *= (1 + 2); // Check precedence -> assignment operator의 precedence은 매우 낮음

	for (int i = 0; i < 10; i += 2) {
		;
	}


	/*
		어셈블리 코드 확인법

		1. 보고 싶은 곳 break point 지정
		2. debuger 실행
		3. 우클릭 후 go to disassembly or debug - windows - disassembly
	*/

	return 0;
}