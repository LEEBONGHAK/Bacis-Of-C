#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	// Entry-Conditon Loop While 문의 성질 정리
	/* 기본적인 문법
	while (expression)
		statement
	*/

	int i;

	//i = 1;
	//while (i < 5)			// infinite loop
	//	printf("Hi!\n");	// interation (반복하는 것)


	//i = 1;
	//while (--i < 5)		// wrong direction
	//	printf("Hi!\n");


	//i = 1;
	//while (i < 5) {
	//	printf("i before = %d\n", i);
	//	i++;
	//	printf("i after = %d\n", i);
	//}


	//i = 10;
	//while (i++ < 5) {		// cannot enter
	//	printf("Hi!\n");
	//}


	/* Common mistakes */

	// {} 사용하지 않음
	//i = 0;
	//while (i < 3)
	//	printf("%i\n", i);
	//	i++;				// indenting


	//i = 0;
	//while (i++ < 3);		// null statement
	//	printf("%i\n", i);


	while (scanf("%d", &i) == 1)
		;					// null statement
	// do something (?)


	return 0;
}