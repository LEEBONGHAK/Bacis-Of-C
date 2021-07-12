#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	int arr[10];

	const int num = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < num; ++i) {
		arr[i] = (i + 1) * 100;
	}

	int* ptr = arr;

	printf("%p %p %p\n", ptr, arr, &arr[0]);		// 주소 동일

	ptr += 2;

	printf("%p %p %p\n", ptr, arr + 2, &arr[2]);	// 주소 동일

	// Note: arr += 2;	// invalid

	printf("%d %d %d\n", *(ptr + 1), *(arr + 3), arr[3]);	// 값 동일

	// Warning
	printf("%d %d %d\n", *ptr + 1, *arr + 3, arr[3]);
	printf("\n");


	/*
	int* ptr = NULL;
	ptr = arr;		// 요즘은 이렇게 써도 무방
	*/
	for (int i = 0, *ptr = arr; i < num; ++i) {		// 실무에서 많이 쓰이는 경우
		//printf("%d %d\n", *ptr++, arr[i]);
		//printf("%d %d\n", *(ptr + i), arr[i]);
		printf("%d %d\n", *ptr + i, arr[i]);
	}
	printf("\n");


	return 0;
}