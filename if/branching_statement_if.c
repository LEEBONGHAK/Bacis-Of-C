#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	/*
		if (expression) {
			statement
		}
	*/
	int number;

	printf("Inpute a positive integer : ");
	scanf("%d", &number);

	if (number % 2 == 0) {
		printf("Even\n");
	}

	if (number % 2 != 0) {
		printf("Odd\n");
	}


	/*
		if (expression) {
			statement1
		}
		else {
			statement2
		}
	*/
	int number2;

	printf("Inpute a positive integer : ");
	scanf("%d", &number2);

	if (number2 % 2 == 0) {
		printf("Even\n");
	}
	else {
		printf("Odd\n");
	}

	return 0;
}