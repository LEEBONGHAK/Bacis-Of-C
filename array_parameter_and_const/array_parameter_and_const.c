#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void print_array(const int arr[], const int n) {
	for (int i = 0; i < n; ++i) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void add_value(int arr[], const int n, const int val) {
	for (int i = 0; i < n; i++) {
		arr[i] += val;
	}
}

// 예방책으로 const를 사용 - 실수를 더 방지하기 좋음
int sum(const int arr[], const int n) {
	int total = 0;

	for (int i = 0; i < n; i++) {
		//total += arr[i]++;		//wrong implementation - error by const
		total += arr[i];
	}

	return total;
}

int main() {
	int arr[] = { 1,2,3,4,5 };
	const int n = sizeof(arr) / sizeof(arr[0]);

	print_array(arr, n);
	add_value(arr, n, 100);
	print_array(arr, n);

	int s = sum(arr, n);
	printf("sum is %d\n", s);
	print_array(arr, n);

	return 0;
}