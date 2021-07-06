#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	int c;

	/*
		#define EOF    (-1) in stdio.h

		EOF 사용
		1. ctrl + z	: 프로그램 종료
		2. ctrl + c : 강제 종료	
	*/

	while ((c = getchar()) != EOF) {	// End Of Fil
		putchar(c);
	}

	// stream : 데이터의 흐름
	// EOF -> stream이 어디에서 끝나는 지 표시하는 것
	while (1) {
		c = getchar();
		printf("%d\n", c);

		if (c == EOF) {
			break;
		}
	}

	return 0;
}