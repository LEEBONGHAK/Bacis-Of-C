#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <ctype.h>		// islower()
#include <stdbool.h>
#include <iso646.h>		// and, or, not (c언어에서 많이 사용하진 않음)

#define PERIOD '.'

int main() {
	/*
		Logical operators

		&& : and
		|| : or
		!  : not
	*/

	bool test1 = 3 > 2 || 5 > 6;	// true
	bool test2 = 3 > 2 && 5 > 6;	// false
	bool test3 = !(5 > 6);			// true, equivalent to 5 <= 6

	printf("%d %d %d\n", test1, test2, test3);	// 1 0 1


	/* Character counting example */
	char ch;
	int count = 0;

	while ((ch = getchar()) != PERIOD) {	// . 을 해야 종료
		// TODO : make exceptions
		if (ch != '\n' && ch != ' ') {
			count++;
		}
	}

	printf("%d\n", count);


	/*
		c 또는 c++에서는 잘 안쓰임
		Alternatives in iso646.h

		&& : and
		|| : or
		!  : not
	*/

	bool test4 = 3 > 2 or 5 > 6;	// true
	bool test5 = 3 > 2 and 5 > 6;	// false
	bool test6 = not(5 > 6);		// true, equivalent to 5 <= 6

	printf("%d %d %d\n", test4, test5, test6);	// 1 0 1

	/*
		Precedence

		Check !, &&, || in the operator precedence table
		https://en.cppreference.com/w/c/language/operator_precedence
	*/

	int a = 1, b = 2, c = 3, d = 4;

	a > b && b > c || b > d;
	((a > b) && (b > c)) || (b > d);

	
	/*
		Short-circuit Evaluation

		- Logical expressiond are evaluated from left to right
		- && and || are sequence points
	*/

	int temp = (1 + 2) * (3 + 4);

	printf("Before : %d\n", temp);			// 21

	if (temp == 0 && (++temp == 1024)) {	// 앞에 false로 판명되었기 때문에 중단되고, ++temp가 실행되지 않음
		// do nothing
	};

	printf("After : %d\n", temp);			// 21


	int x = 1, y = 2;
	if (x++ > 0 && x + y == 4) {
		printf("%d %d\n", x, y);			// 2 2
	}


	/* Ranges */
	for (int i = 0; i < 100; ++i) {
		if (i >= 10 && i <= 20) {
			printf("%d ", i);	// 10 11 12 13 14 15 16 17 18 19 20
		}
	}
	printf("\n");

	for (int i = 0; i < 100; ++i) {
		if (10 <= i <= 20) {
			printf("%d ", i);	// Not : if ((10<= i) <= 20) -> 논리적 판단이 되어 버림
		}
	}	// 0부터 99까지 모두 출력
	printf("\n");


	// 더 직관적
	for (char c = -128; c < 127; ++c) {
		if (c >= 'a' && c <= 'z') {
			printf("%c ", c);
		}
	}
	printf("\n");

	// 더 깔끔
	for (char c = 0; c < 127; ++c) {
		if (inlower(c)) {
			printf("%c ", c);
		}
	}

	return 0;
}