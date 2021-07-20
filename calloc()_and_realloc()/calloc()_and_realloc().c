#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main() {
	int n = 10;
	int* ptr = NULL;
	
	/* calloc() */
	//ptr = (int*)malloc(sizeof(int) * n);
	ptr = (int*)calloc(n, sizeof(int));		// contiguous allocation - 서로 인접한 메모리들을 요청하며, 0으로 초기화를 해줌
	if (!ptr) {
		exit(1);
	}

	for (int i = 0; i < n; ++i) {
		printf("%d ", ptr[i]);
	}
	printf("\n\n");


	/*
		realloc() KNK p. 442   -> reallocation (재할당) : 다시 할당 받고 싶을 때 사용
		- doesn't initialize the bytes added
		- returns NULL if can't enlarge the memory block
		- if first argument is NULL, it behaves like malloc()
		- if second argument is 0, it frees the memory block
	*/
	for (int i = 0; i < n; ++i) {
		ptr[i] = i + 1;
	}

	n = 20;

	int* ptr2 = NULL;
	ptr2 = (int*)realloc(ptr, n * sizeof(int));
	//ptr = (int*)realloc(ptr, n * sizeof(int));	// Ok

	printf("%p %p\n", ptr, ptr2);

	printf("%d\n", ptr[0]);

	if (!ptr2) {
		exit(1);
	}
	else {
		ptr = NULL;
	}

	for (int i = 0; i < n; ++i) {
		printf("%d ", ptr2[i]);		// copies data
	}
	printf("\n");

	free(ptr2);
	ptr2 = NULL;

	return 0;
}