#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>		// strlen()

#define WIDTH	30
#define NAME	"Bong-Hak Lee"
#define ADDRESS	"Seoul, Korea"

void print_bar() {
	printf("********************\n");
}

void print_bar2(int n_stars) {
	for (int i = 0; i < n_stars; ++i) {
		printf("*");
	}
	printf("\n");
}

void print_blank(int n_blank) {
	for (int i = 0; i < n_blank; ++i) {
		printf(" ");
	}
}

void print_multiple_chars(char c, int n_star) {
	for (int i = 0; i < n_star; ++i) {
		printf("%c", c);	// putchar(c);
	}
}

void print_centered_str(char str[]) {
	int n_blank = (WIDTH - strlen(str)) / 2;
	print_multiple_chars(' ', n_blank);
	printf("%s\n", str);
}

// 코드를 작성할 때 일반화의 관점에서 많은 경우에 대응할 수 있도록
// 같은 기능이 여러번 나오지 않게 (유지 보수를 위해)
int main() {
	int n_blanks = 0;

	// 표현 1
	printf("********************\n");
	printf("    Bong-Hak Lee\n");
	printf("    Seoul, Korea\n");
	printf("********************\n");
	printf("\n");

	
	// 표현 2
	print_bar();
	printf("    Bong-Hak Lee\n");
	printf("    Seoul, Korea\n");
	print_bar();
	printf("\n");


	// 표현 3 - WIDTH에 따라 가운데 정렬이 안됨
	print_bar2(WIDTH);
	printf("    %s\n", NAME);
	printf("    %s\n", ADDRESS);
	print_bar2(WIDTH);
	printf("\n");


	// 표현 4
	print_bar2(WIDTH);
	print_blank(4);
	printf("%s\n", NAME);
	print_blank(4);
	printf("%s\n", ADDRESS);
	print_bar2(WIDTH);
	printf("\n");


	// 표현 5
	print_multiple_chars('*', WIDTH);
	printf("\n");
	print_multiple_chars(' ', 4);
	printf("%s\n", NAME);
	print_multiple_chars(' ', 4);
	printf("%s\n", ADDRESS);
	print_multiple_chars('*', WIDTH);
	printf("\n\n");


	// 표현 6
	print_multiple_chars('*', WIDTH);
	printf("\n");

	n_blanks = (WIDTH - strlen(NAME)) / 2;
	print_multiple_chars(' ', n_blanks);
	printf("%s\n", NAME);

	n_blanks = (WIDTH - strlen(ADDRESS)) / 2;
	print_multiple_chars(' ', n_blanks);
	printf("%s\n", ADDRESS);

	print_multiple_chars('*', WIDTH);
	printf("\n\n");


	// 표현 7
	print_multiple_chars('*', WIDTH);
	printf("\n");

	print_centered_str(NAME);
	print_centered_str(ADDRESS);

	print_multiple_chars('*', WIDTH);
	printf("\n\n");

	return 0;
}