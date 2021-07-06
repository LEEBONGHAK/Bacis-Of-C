#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>		// Windows에서만 작동, 버퍼를 사용하지 않는 함수 => _getch(), _getche()

int main() {
	char c;

	//while ((c = getchar()) != '.') {	// 버퍼 사용
	while ((c=_getche()) != '.') {		// 입력할 때마다 바로 출력, e = echo
		putchar(c);
	}

	while ((c = _getch()) != '.') {		// echo가 없음
		putchar(c);
	}
	printf("\n");

	return 0;
}