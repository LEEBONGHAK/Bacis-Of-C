﻿#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void my_func(int);

// 재귀 호출(recursion) : 자기 자신을 호출하는 함수
int main() {
	my_func(1);

	return 0;
}

void my_func(int n) {
	printf("Level %d, address of variable n = %p\n", n, &n);

	// stop condition
	if (n < 4)
		my_func(n + 1);

	printf("Level %d, address of variable n = %p\n", n, &n);
}