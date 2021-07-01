#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	/* promotions(승진) in assignments */
	short s = 64;
	int i = s; // short < int

	float f = 3.14f;
	double d = f; // float < double

	/* demotion(데이터가 큰 자료형은 작은 자료형에 넣으려고 하는 것) in assignments */
	d = 1.25;
	f = 1.25; 
	f = 1.123f; 
	// f = 1.123; // truncation(절삭) error
	

	/* ranking of types in operations */
	// 아래로 내려갈 수록 ranking이 낮고, 같은 줄은 같은 ranking
	// float < double < long double
	// unsigned long long, long long
	// unsigned long, long
	// unsigned, int
	// short int, unsigned short int
	// signed char, char, unsigned char
	// _Bool
	// Ref : Google 'Integer conversion rank'
	d = f + 1.234; // 내부적으로 double로 변환 후 계산
	f = f + 1.234; // 1.234 가 double이기 때문에 truncation error


	/* automation promotion of function arguments */
	// 1. Function without prototypes (C99에 prototype이 도입이 되면서 잘 안쓰임)
	// 2. Variadic functions (인수가 변할 수 있는 경우 / 많이 쓰이진 않지만 알아두는 것이 좋음(ellipsis))


	/* casting operators (형변환을 할 것이라고 의도적으로 명시해주는 경우) */
	d = (double)3.14f; // float -> double
	i = 1.6 + 1.7; // truncation error => 3
	i = (int)1.6 + (int)1.7; // 1 + 1 = 2


	/* more examples */
	char c;
	// int i;
	// float f;
	f = i = c = 'A'; // 65 (int와 float는 크기는 같지만 유효숫자가 다름)
	printf("%c %d %f\n", c, i, f); // A 65 65.000000
	c = c + 2; // 'C', 67
	i = f + 2 * c; // 65.0f + 2 * 67
	printf("%c %d %f\n", c, i, f); // C 199 65.000000
	c = 1106; // demolition, 1106 = 0b10001010010 (1 byte보다 커서 짤라냄) => 0b01010010 = 1106 % 256 = 82 = 'R'
	printf("%c\n", c); // R
	c = 83.99;
	printf("%c\n", c); // S(83) by truncation

	return 0;
}