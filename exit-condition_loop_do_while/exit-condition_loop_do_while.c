#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	const int secret_code = 337;
	
	int guess = 0;

	printf("Enter secret code : ");
	scanf("%d", &guess);

	while (guess != secret_code) {
		printf("Enter secret code : ");
		scanf("%d", &guess);
	}

	printf("Good!\n");


	// do while문 사용하기 - 비교를 하기전에 무조건 1 번은 실행함
	do {
		printf("Enter secret code : ");
		scanf("%d", &guess);
	} 
	while (guess != secret_code);

	printf("Good!\n");

	return 0;
}