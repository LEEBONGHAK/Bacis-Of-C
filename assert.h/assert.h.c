#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include <assert.h>		// assert library

//#include <limits.h>
//_Static_assert(CHAR_BIT == 16, "16-bit char falsely assumed");  // not allowed in VS - 컴파일 타임에서 잡아주는 assert

int divide(int a, int b);

int main() {
	int a, b;
	int f = scanf("%d%d", &a, &b);

	printf("a / b = %d\n", divide(a, b));

	return 0;
}

int divide(int a, int b) {
	assert(b != 0);		// 반드시 만족해야하는 조건 - 디버깅 도구 중 하나

	//if (b == 0) {
	//	printf("Cannot divide\n");
	//	exit(1);
	//}

	return a / b;
}