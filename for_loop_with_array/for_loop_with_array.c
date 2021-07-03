#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define SIZE 5

int main() {
	/* Motivation */
	int i1 = 0;
	int i2 = 1;
	int i3 = 2;
	// ...

	printf("%d\n", i1);
	printf("%d\n", i2);
	printf("%d\n", i3);
	// ...


	int my_arr[SIZE];

	// prepare for array data
	for (int i = 0; i < SIZE; ++i) {
		my_arr[i] = i;
	}

	// print array data
	for (int i = 0; i < SIZE; ++i) {
		printf("%d ", my_arr[i]);
	}
	printf("\n");


	// 예제
	int numbers[SIZE];
	int sum = 0;

	printf("Enter %d numbers : ", SIZE);

	for (int i = 0; i < SIZE; ++i) {
		scanf("%d", &numbers[i]);
	}

	for (int i = 0; i < SIZE; ++i) {
		sum += numbers[i];
	}

	printf("Sum = %d\n", sum);
	printf("Average = %d\n", sum / SIZE);

	return 0;
}