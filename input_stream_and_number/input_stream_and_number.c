#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	/* 
		Assume that your input is :
		Hello 123 3.14
	*/
	char str[255];
	int i, i2;
	double d;

	scanf("%s %d %lf", str, &i, &d);
	printf("%s %d %lf\n", str, i, d);	// Hello 123 3.140000


	// or (see the difference)
	scanf("%s %d %d", str, &i, &i2);
	printf("%s %d %d\n", str, i, i2);	// Hello 123 3 - scanf가 자체적으로 입력을 조절함


	// or (see the difference)
	char c;
	while ((c = getchar()) != '\n')
		putchar(c);						// .14	- buffer에 남은 문자들을 출력함
	printf("\n");


	return 0;
}