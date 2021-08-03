#define _CRT_SECURE_NO_WARNINGS

/*
	Various Preprocessor Directives

	#define, #undef, #if, #ifdef, #ifndef, #else, #elif, #endif
*/

#include <stdio.h>

// project properties-preprocessor-preprocessor definitions에서 미리 정의도 가능
#define REPORT

int sum(int i, int j) {
	int s = 0;
	for (int k = i; k <= j; ++k) {
		s += k;

#ifdef _DEBUG		// build 옵션을 통해 여러 활용 가능
		printf("test debug\n");
#endif // _DEBUG


#ifdef REPORT
		printf("%d %d\n", s, k);
#endif // REPORT
	}

	return s;
}


int main() {
	printf("\n%d \n", sum(1, 10));


	return 0;
}