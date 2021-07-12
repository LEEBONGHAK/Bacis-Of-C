#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

double average(double*, double*);

int main() {
	double arr1[5] = { 10,13,12,7,8 };

	printf("Avg = %f\n", average(arr1, arr1 + 5));

	return 0;
}

double average(double* start, double* end) {
	int count = 0;
	//int count = end - start;
	double avg = 0.0;

	while (start < end) {
		avg += *start++;	// 주소가 가진 원소의 값을 더하고 다음 원소의 주소로 증가
		count++;
	}
	avg /= count;

	return avg;
}