#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// 함수에서 배열을 받을 때 배열로 받지 않고 포인터로 받음 (주의 !)
// 따라서 배열의 개수를 따로 받을 수 있게 매개변수 설정 (주의 !)
double average(double arr[], int n) {
	printf("Size = %zd in function average\n", sizeof(arr));	// 포인터의 사이즈가 나옴 즉, 포인터처럼 처리됨

	double avg = 0.0;
	for (int i = 0; i < n; ++i) {
		avg += arr[i];
	}
	avg /= (double)n;

	return avg;
}

int main() {
	double arr1[5] = { 10,13,12,7,9 };
	//double arr2[5] = { 1.8,-0.2,6.3,13.9,20.5 };
	double arr2[3] = { 1.8,-0.2,6.3 };		// size is different

	printf("Address = %p\n", arr1);
	printf("Size = %zd\n", sizeof(arr1));

	double avg = 0.0;
	for (int i = 0; i < 5; ++i) {
		avg += arr1[i];
	}
	avg /= (double)5;

	printf("Avg = %f\n", avg);
	//printf("Avg = %f\n", average(arr1));
	//printf("Avg = %f\n", average(arr2));

	printf("Avg = %f\n", average(arr1, 5));
	printf("Avg = %f\n", average(arr2, 3));

	return 0;
}

/*
	가능한 여러가지 prototype들 

	double average(double arr[], int n);
	double average(double * arr, int n);
	double average(double *, int n);	// 아래 것보다 이게 더 좋음
	double average(double [], int n);
*/