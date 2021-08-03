#define _CRT_SECURE_NO_WARNINGS

/*
	Various Preprocessor Directives

	#define, #undef, #if, #ifdef, #ifndef, #else, #elif, #endif
*/

#include <stdio.h>
#include "Header_B.h"
//#include "Header_A.h"		//-> 중복 include될 경우 (Error) -> header guard로 방지 가능

int main() {
	test_function_A();
	test_function_B();

	return 0;
}