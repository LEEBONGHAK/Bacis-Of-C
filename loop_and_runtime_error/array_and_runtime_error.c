#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define NUM_DAYS 365

int main() {
	char my_chars[] = "Hello, World!";

	int daily_temperature[NUM_DAYS];
	double stock_prices_history[NUM_DAYS];

	printf("%zd\n", sizeof(stock_prices_history));		// 2920
	printf("%zd\n", sizeof(double) * NUM_DAYS);			// 8 * 365
	printf("%zd\n", sizeof(stock_prices_history[0]));	// 8


	int my_numbers[5];			// 변수 이름은 연속적으로 할당되는 첫 번째 주소와 대응한다.

	my_numbers[0] = 1;			// subscripts, indices, offsets
	my_numbers[1] = 3;
	my_numbers[2] = 4;
	my_numbers[3] = 2;
	my_numbers[4] = 1024;

	//scanf("%d", &my_numbers[0]);
	scanf("%d", my_numbers);		// my_numbers[0]에 저장됨

	printf("%d\n", my_numbers[0]);	
	printf("%d\n", my_numbers[1]);	
	printf("%d\n", my_numbers[2]);	
	printf("%d\n", my_numbers[3]);	
	printf("%d\n", my_numbers[4]);


	/* Runtime Error - 실행할 때 에러가 발생한다. */
	//my_numbers[5] = 123;			// out of bound - 컴파일할 때 잡아주지 않고 실행할 때 runtime error

	//my_numbers = 7;				// compile error

	//printf("%d\n", my_numbers[5]);	//out of bound

	return 0;
}