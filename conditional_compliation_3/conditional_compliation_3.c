#define _CRT_SECURE_NO_WARNINGS

/*
	Various Preprocessor Directives

	#define, #undef, #if, #ifdef, #ifndef, #else, #elif, #endif
*/

#include <stdio.h>

#define TYPE 1

#if TYPE == 1
#include "my_function_1.h"
#elif TYPE == 2
#include "my_function_2.h"
#else
static void my_function() {
	printf("Wrong compile option!\n");
}
#endif

int main() {
	my_function();

	return 0;
}