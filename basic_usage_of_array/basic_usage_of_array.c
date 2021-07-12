#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MONTH 12		// symbolic constant, macro

int main() {
	/* Basic usage */
	int high[MONTH] = { 2,5,11,18,23,27,29,30,26,20,12,4 };

	for (int i = 0; i < MONTH; ++i) {
		printf("%d ", high[i]);
	}
	printf("\n");


	float avg = 0.0;
	for (int i = 0; i < MONTH; ++i) {
		avg += high[i];
	}
	printf("Average = %f\n", avg / (float)MONTH);
	printf("\n");


	high[0] = 1;
	high[1] = 2;
	//high = { 2,5,11,18,23,27,29,30,26,20,12,4 };		// Not working
	//high[12] = { 2,5,11,18,23,27,29,30,26,20,12,4 };	// Not working


	/* Addresses */
	printf("%p %p\n", high, &high[0]);
	for (int i = 0; i < MONTH; ++i) {
		printf("%lld\n", (long long)&high[i]);
	}
	printf("\n");


	/* Compiler doesn't check whether indices are valid */
	//high[12] = 4;	// Error
	//high[-1] = 123;	// Error


	/* cont and array */
	const int temp = 0;
	//temp = 4;	// Error
	const int low[12] = { -7,-5,1,7,13,18,22,22,16,9,2,-5 };
	//low[0] = 123;	// Error


	/* When array is not initialized */
	//static int not_init[4];
	int not_init[4];		// TODO: try static (storage class)
	for (int i = 0; i < 4; ++i) {
		printf("%d\n", not_init[i]);	// debug이냐 release이냐 등 환경이나 컴파일러에 따라 출력 결과가 바뀔 수 있음
	}
	printf("\n");


	/* Partially initialized */
	int insuff[4] = { 2,4 };
	for (int i = 0; i < 4; ++i) {
		printf("%d\n", insuff[i]);	// 부족한 부분은 알아서 채워줌
	}
	printf("\n");


	/* Overlly initialized */
	//int over[2] = { 2,4,8,16 };	// compiler error


	///* Omitting size */
	const int power_of_twos[] = { 1,2,4,8,16,32,64 };	// 데이터의 개수가 너무 많거나 잘 알 수 없는 경우 사용
	printf("%d\n", sizeof(power_of_twos));		// 동적 할당에서는 사용하지 못함 (매우 주의 !)
	printf("%d\n", sizeof(int));
	printf("%d\n", sizeof(power_of_twos[0]));

	// 배열의 크기를 알 수 없기 때문에 sizeof를 사용해 for문을 사용
	for (int i = 0; i < sizeof(power_of_twos) / sizeof(power_of_twos[0]); ++i) {
		printf("%d ", power_of_twos[i]);
	}
	printf("\n\n");


	/* Designed initializers (초기화 지정) */
	int days[MONTH] = { 31,28,[4] = 31,30,31,[1] = 29 };
	for (int i = 0; i < MONTH; ++i) {
		printf("%d ", days[i]);
	}
	printf("\n");


	/* Specifying Array sizes */
	int arr1[MONTH];		// Symbolic integer constant
	double arr2[123];		// Literal integer constant
	float arr3[3 * 4 + 1];
	float arr4[sizeof(int) + 1];
	//float arr5[-10];		// No
	//float arr6[0];		// No
	//float arr7[1.5];		// No
	float arr8[(int)1.5];	// Yes

	//int n = 8;
	//float arr9[n];			// Variable-Length Array is optional from C11 -> 컴파일러마다 다름

	/*
	int n = 5;
	float arr[n];

	for (int i; i < n; ++i)
		arr[i] = (float)i;

	for (int i; i < n; ++i)
		printf("%f ", arr[i]);
	
	return 0;
	*/

	return 0;
}