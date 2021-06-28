#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	/*
	int i = 0, j = 0;
	int sum = 0;

	printf("Input two integers : ");
	scanf("%d%d", &i, &j);

	printf("Your numbers are %d and %d\n", i, j);

	sum = i + j;

	printf("%d + %d = %d\n", i, j, sum);
	printf("%d + %d = %d\n", i, j, i + j);
	*/
	
	float won = 0;
	float doller = 0;

	printf("Input won : ");
	scanf("%f", &won);

	// float형 literal constant로 변환시켜주기 위해 뒤에 'f'를 붙임
	doller = won * 0.00089f; 

	printf("Dollar = %f\n", doller);

	return 0;
}