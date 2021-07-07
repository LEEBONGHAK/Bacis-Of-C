#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int int_min(int, int);

int main() {
	int i1, i2;

	while (1) {
		printf("Input two integers : ");

		if (scanf("%d %d", &i1, &i2) != 2) {
			break;
		}

		int lesser = int_min(i1, i2);
		//int lesser = min;
		printf("The lesser of %d and %d is %d\n", i1, i2, lesser);

		//printf("The lesser of %d and %d is %d\n", i1, i2, int_min(i1, i2));
	}

	printf("End.\n");

	return 0;
}

// 정수형 반환 함수의 경우 자료형을 생략가능
// 그러나 생략은 안하는 것을 추천
//int int_min(int i, int j) {
int_min(int i, int j) {
	// 방법 1
	int min;

	if (i < j) {
		min = i;
	}
	else {
		min = j;
	}

	return min;


	// 방법 2
	//return (i < j) ? i : j;


	// 방법 3
	/*
	if (i < j) {
		return i;
	}
	else {
		return j;
	}
	printf("Who am I?\n");		// 출력 안됨 - return 이후 함수 종료
	*/

	//return;					// return with no value
}