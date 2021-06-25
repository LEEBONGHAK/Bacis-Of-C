// scanf() 에러 해결법 1
// #define _CRT_SECURE_NO_WARNINGS

// scanf() 에러 해결법 2 
// project 우클릭, properties, c/c++. preprecessor에 _CRT_SECURE_NO_WARNINGS 추가

#include <stdio.h>

int main() {
	int i = 0;

	// scan formated
	scanf("%d", &i); // & : ampersand

	// print formated
	printf("Value is %d\n", i);

	return 0;
}