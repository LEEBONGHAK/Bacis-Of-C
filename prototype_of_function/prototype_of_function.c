#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>		// strlen()
#include <stdbool.h>

#define WIDTH	30
#define NAME	"Bong-Hak Lee"
#define ADDRESS	"Seoul, Korea"

// 함수의 prototype만 있어도 가능 (입력값, 반환값이 명시 되어 있음) 
// - 함수 내용이 없어도 컴파일 에러가 없으며, 실제 실행 파일을 만드는 링킹(linking)이 안됨
void print_multiple_chars(char c, int n_star, bool print_newline);
void print_centered_str(char str[]);

int main() {
	print_multiple_chars('*', WIDTH, true);		// actual argument/parameter

	print_centered_str(NAME);
	print_centered_str(ADDRESS);
	print_centered_str("I love you");

	print_multiple_chars('*', WIDTH, true);
	printf("\n");

	return 0;
}

void print_multiple_chars(char c, int n_star, bool print_newline) {		// formal (argument/paramerter)
	for (int i = 0; i < n_star; ++i) {
		printf("%c", c);	// putchar(c);
	}

	if (print_newline == true) {
		printf("\n");
	}
}

void print_centered_str(char str[]) {
	int n_blank = 0;
	n_blank = (WIDTH - strlen(str)) / 2;
	print_multiple_chars(' ', n_blank, false);
	printf("%s\n", str);
}