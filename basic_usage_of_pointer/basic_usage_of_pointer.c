#define _CRT_SECURE_NO_WRNINGS

#include <stdio.h>

int main() {
	int a, b;
	
	a = 123;

	int *a_ptr;		// * : asterisk

	a_ptr = &a;		// & : address-of operator
	printf("%d %d %p\n", a, *a_ptr, a_ptr);

	*a_ptr = 456;	// * : re-direction or de-referencing
	printf("%d %d %p\n", a, *a_ptr, a_ptr);


	//b = a_ptr;
	b = *a_ptr;

	printf("%d\n", b);


	*a_ptr = 789;

	printf("%d %p\n", b, &b);
	printf("%d %d %p\n", a, *a_ptr, a_ptr);


	b = 12;
	
	printf("%d\n", b);
	printf("%d %d %p\n", a, *a_ptr, a_ptr);

	
	a = 1004;

	printf("%d %d %p\n", a, *a_ptr, a_ptr);

	return 0;
}

/* Coding style */
/*
	int *a_ptr vs int* a_ptr
	int* my_ptr, sec_ptr;	// 포인터와 int형 선언
	int *my_ptr, sec_ptr;	// 포인터와 int형 선언	
*/