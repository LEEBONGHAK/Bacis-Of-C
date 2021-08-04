#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>		// memcpy(), memmove() - 메모리 데이터 카피, 메모리 데이터 이동

#define LEN 6

void prt(int* arr, int n) {
	for (int i = 0; i < n; ++i)
		printf("%d ", arr[i]);
	printf("\n");
}

int main() {
	/*
		- overlapping region
		- pointer-to-void (datatype is unknown)
	*/
	
	int arr1[LEN] = { 1,3,5,7,9,11 };
	//int arr2[LEN] = { 0, };
	int* arr2 = (int*)malloc(LEN * sizeof(int));
	if (arr2 == NULL) {
		exit(1);
	}

	for (int i = 0; i < LEN; ++i) {			// memcpy 사용 안했을 때
		arr2[i] = arr1[i];
	}

	memcpy(arr2, arr1, sizeof(int) * LEN);	// memcpy 사용
	prt(arr2, LEN);
	printf("\n");



	/*
	memcpy와 memmove는 비슷하지만 차이점 존재, 그러나 컴파일러에 따라 다름
	
	{ 1, 3, 5, 7,  9, 11 }
	{ 5, 7, 9, 11, 9, 11 }

	겹치는 부분 존재할 경우 memcpy 사용 시 문제가 생길 수 있음
	memmove의 경우 buffer(컴피알러에 따라 다르지만)에 일시적으로 저장 후 그 다음에 저장하기 때문에 겹치는 부분이 있어도 문제가 없음
	*/
	prt(arr1, LEN);
	//memcpy(arr1, &arr1[2], sizeof(int) * 4);		// undefined behavior
	memmove(arr1, &arr1[2], sizeof(int) * 4);
	prt(arr1, LEN);

	return 0;
}