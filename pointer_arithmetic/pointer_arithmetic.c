#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	int* normal_ptr = NULL;	// 일반적으로는 이게 더 좋음
	int* ptr = 0;		// try double*, long long*, char*, void*

	//printf("%d", *ptr);		//Error in this lecture

	printf("%p %lld\n", ptr, (long long)ptr);

	//ptr = ptr +1;		// void 포인터의 경우 산술계산 불가
	ptr ++;		// try -=, ++, --, -, +

	printf("%p %lld\n", ptr, (long long)ptr);	// 자료형의 메모리 크기만큼 증가

	//ptr = -ptr;	// Not working and not meaingful
	//ptr = +ptr;	// Not working and not meaingful


	/* Subtraction */
	int arr[10];
	int* ptr1 = &arr[3], * ptr2 = &arr[5];

	//ptr2 = ptr1 + ptr2;		// Not working and not meaingful
	int i = ptr2 - ptr1;		// 단순히 주소값을 빼는 것이 아닌 메모리가 떨어져 있는 정도를 나타냄

	printf("%p %lld %p %lld %d\n", ptr1, (long long)ptr1, ptr2, (long long)ptr2, i);

	return 0;
}