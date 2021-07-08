#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

/*
	Fibonacci sequence
	1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144

	ex) fibonacci(5) = 3 + 2 = fibonacci(4) + fibonacci(3)
	ex) fibonacci(6) = 5 + 3 = fibonacci(5) + fibonacci(4)
*/

int fibonacci(int number);

int main() {
	for (int count = 1; count < 13; ++count) {
		printf("%d ", fibonacci(count));
	}
	printf("\n");

	return 0;
}

int fibonacci(int number) {
	// 내 코드
	/*if (number == 1 || number == 2) {
		return 1;
	}

	int i = fibonacci(number - 1) + fibonacci(number - 2);

	return i;*/


	// 강의 코드
	if (number > 2) {
		return fibonacci(number - 1) + fibonacci(number - 2);	// double recursion
	}
	else {
		return 1;
	}
}

/*
	disadvantages of recursion

	1. memory (in)efficiency (메모리를 많이 씀)
	2. redundant computation (계산의 중복 발생)
*/