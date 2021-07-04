#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	int number;
	scanf("%d", &number);

	if (number == 1) 
		printf("One\n");
	else if (number == 2)
		printf("Two\n");
	else if (number == 3) 
		printf("Three\n");


	// 권장되지 않음
	if (number == 1) 
		printf("One\n");
	else 
		if (number == 2) 
			printf("Two\n");
		else 
			if (number == 3) 
				printf("Three\n");

	// minimum 127 levels of nestings

	
	if (number > 5) 
		if (number < 10) 
			printf("Larger than 5 smaller than 10\n");
	else // 안나옴
		printf("Less than or equal to 5");

	// Compilers ignore indenting
	// else는 indenting과 상관없이 가까이에 있는 if문에 붙는다.
	// 헷갈릴 여지가 있다면 {}을 사용

	return 0;
}
