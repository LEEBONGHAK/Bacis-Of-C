#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	int num, sum = 0;
	int status;
	
	printf("Enter an integer (q to quit) : ");
	status = scanf("%d", &num);			// return value of scanf() => 입력 받은 갯수

	while (status == 1) {				// equality operator
		sum += num;

		printf("Enter next integer (q to quit) : ");
		status = scanf("%d", &num);
	}

	printf("Sum = %d\n", sum);


	// TODO : C-style shortcut
	printf("Enter an integer (q to quit) : ");

	while (scanf("%d", &num) == 1) {				// equality operator
		sum += num;

		printf("Enter next integer (q to quit) : ");
	}

	printf("Sum = %d\n", sum);

	return 0;
}