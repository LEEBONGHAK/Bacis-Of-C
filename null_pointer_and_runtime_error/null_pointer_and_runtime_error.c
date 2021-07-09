#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	int a;		// 초기화하지 않으면 쓰레기 값이 들어가 있음

	printf("%p\n", &a);
	printf("%d\n", a);
	
	
	/*int* ptr;	// 쓰레기 값이 주소가 되지 않기 때문에 error 발생

	printf("%p\n", ptr);
	printf("%d\n", *ptr);*/


	//int* safer_ptr;		// = NULL
	int* safer_ptr = NULL;	// 일반적인 사용법 -> 포인터 초기화
	int a1 = 123;
	int b;
	scanf("%d", &b);

	//safer_ptr = &a;		// 직접 할당

	if (b % 2 == 0) {	// 더 많이 쓰임
		safer_ptr = &a1;
	}

	if (safer_ptr != NULL) {
		printf("%p\n", safer_ptr);
	}

	if (safer_ptr != NULL) {
		printf("%d\n", *safer_ptr);
	}

	return 0;
}