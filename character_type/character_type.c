#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	char c = 'A'; // char type에는 문자가 하나씩만 들어갈 수 있음
	char d = 65; // d = 'A'

	printf("%c %hhd\n", c, c);
	printf("%c %hhd\n", d, d);

	printf("%c \n", c + 1);

	char a = '\a'; // a = \7(10진수) or \07(8진수) or \x7(16진수)
	printf("%c\n", a); // BELL 소리를 냄

	float salary;
	printf("$______\b\b\b\b\b\b"); // \b : backspace
	scanf("%f", &salary);

	printf("AB\tCDEF\n"); // \t : tab => 줄을 맞춰줌
	printf("ABC\tDEF\n");

	printf("\\ \'HA+\' \"Hello\" \?\n"); // 특정 문자의 경우 \ 을 사용하여 출력

	return 0;
}