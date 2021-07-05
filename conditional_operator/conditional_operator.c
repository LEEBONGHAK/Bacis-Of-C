#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>

int main() {
	// conditional operator (조건 연산자) = terneray operator (3항 연산자)
	int temp;
	temp = true ? 1024 : 7;
	//temp = 1 ? 1024 : 7;
	printf("%d\n", temp);		// 1024

	temp = false ? 1024 : 7;
	//temp = 0 ? 1024 : 7;
	printf("%d\n", temp);		// 7

	
	int a = 1, b = 2;
	int max = (a > b) ? a : b;	// 2

	int number;
	scanf("%d", &number);

	bool is_even;

	//if (number % 2 == 0) {
	//	is_even = true;
	//}
	//else {
	//	is_even = false;
	//}

	is_even = (number % 2 == 0) ? true : false; 	// ? 연산자는 우선 순위가 낮은 편

	//if (is_even) {
	//	printf("Even\n");
	//}
	//else {
	//	printf("Odd\n");
	//}

	(number % 2 == 0) ? printf("Even\n") : printf("Odd\n");
	printf(is_even ? "Even\n" : "Odd\n");

	return 0;
}