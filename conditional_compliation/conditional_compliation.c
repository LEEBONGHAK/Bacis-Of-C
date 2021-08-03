#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

/*
	Various Preprocessor Directives

	#define, #undef, #if, #ifdef, #ifndef, #else, #elif, #endif
*/

/* #undef */
#define LIMIT 400
//#undef LIMIT		// It's OK to undefine previously NOT defined macro

#undef NON_DEFINED

int main() {
	printf("%d\n", LIMIT);


	return 0;
}