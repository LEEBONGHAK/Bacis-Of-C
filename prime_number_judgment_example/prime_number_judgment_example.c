#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>

int main() {
	unsigned num;
	int isPrime = 1;		// flag, try bool type

	scanf("%u", &num);

	/*
		TODO : Check if num is a prime number
		ex) num is 4, try num % 2, num % 3
		ex) num is 5, try num % 2, num % 3, num % 4
	*/

	// 소수 판별 및 약수 찾기
	for (unsigned div = 2; div < num; ++div) {
		if (num % div == 0) {
			isPrime = 0;

			if (num == div * div) {
				printf("%u is divisible by %u.\n", num, div);
			}
			else {
				printf("%u is divisible by %u and %u.\n", num, div, num / div);

			}
		}
	}

	if (isPrime) {
		printf("%u is a prime number.\n", num);
	}
	else {
		printf("%u is not a prime number.\n", num);
	}

	return 0;
}