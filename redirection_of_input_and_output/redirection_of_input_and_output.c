#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// redirection_of_input_and_output.exe > output.txt : 출력 방향을 콘솔창에서에 output.txt로 재지정(redirection)
// redirection_of_input_and_output.exe < input.txt : input.txt 내용을 받아 콘솔창에서 출력
// redirection_of_input_and_output.exe >> input.txt : 기존 내용을 바꾸지 않고 다음 줄에 출력
// test.exe | redirection_of_input_and_output.exe : pipe 기능

int main() {
	printf("I love apple.\n");

	char str[100];
	scanf("%s", str);
	printf("I love %s\n", str);

	return 0;
}