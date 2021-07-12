#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	// type qualifiers (자료형 한정자/자격자) : const, volatile, ...
	// 변수를 값이 변하지 않은 상수로 변환

	const double PI = 3.14159;
	//double const PI = 3.14159;
	//const double const PI = 3.14159;
	//PI = 2.14159;		// Error


	const int arr[5] = { 1,2,3,4,5 };
	//arr[1] = 123;		// Error - 배열의 각각의 원소들을 바꿀 수 없음


	const double arr2[3] = { 1.0,2.0,3.0 };
	//arr2[0] = 100.0;	// Error


	double* pd = arr2;	// warning C4090: 'initializing': different 'const' qualifiers
	*pd = 3.0;			// pd[0] = 3.0; arr[0] = 3.0; 
	pd[2] = 1024.0;		// arr2[2] = 1024.0;	

	printf("%f %f\n", pd[2], arr2[2]);


	//const double* const pd1 = arr2;		// pd1++; 사용 불가
	const double* pd1 = arr2;
	//*pd1 = 2.0;			// pd[0] = 2.0; arr[0] = 2.0; 
	//pd1[2] = 10.0;		// arr2[2] = 10.0;	

	printf("%f %f\n", pd1[2], arr2[2]);	// 1024.0 1024.0

	pd1++;		// allowed

	printf("%f\n", pd1[1]);		// 1024.0

	return 0;
}