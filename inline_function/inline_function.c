﻿#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

/*
	Function call has overhead
	- set up the call, pass arguments, jump to the function code, and return.

	inline function specifier
	- Suggests inline replacements.
	- 컴파일러가 꼭 함수를 inline으로 컴파일 하지는 않음

	Inline functions should be short.
	A function with internal linkage can be made inline. (GCC, clang)
	You can't take its address
*/

// GCC, clang의 경우 inline static int
inline int foo() {
	return 5;
}

// Driver code
int main() {
	int ret;

	// inline function call
	ret = foo();

	printf("Output is %d\n", ret);


	return 0;
}