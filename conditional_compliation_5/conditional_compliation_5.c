#define _CRT_SECURE_NO_WARNINGS

/*
	Various Preprocessor Directives

	#define, #undef, #if, #ifdef, #ifndef, #else, #elif, #endif
*/

#include <stdio.h>

//#undef _WIN64

void say_hello() {
#ifdef _WIN64		// == #if defined (_WIN64)
	printf("Hello, WIN64\n");
#elif _WIN32
	printf("Hello, WIN32\n");
#elif __linux__
	printf("Hello, linux\n");
#endif
}



int main() {
	say_hello();

	return 0;
}