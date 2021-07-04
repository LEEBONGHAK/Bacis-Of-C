#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <ctype.h>

#define STOP '.'

int main() {
	// 내 코드 - word 수가 제대로 세어지지 않음
	int character_num = 0, word_num = 0, line_num = 1;
	char ch;

	printf("Enter text : \n");

	while ((ch = getchar()) != STOP) {
		if (ch != '\n' && ch != ' ') {
			character_num++;
		}
		else if (ch == ' ') {
			word_num++;
		}
		else if (ch == '\n') {
			line_num++;
		}
	}
	
	printf("Characters = %d, Words = %d, Lines = %d\n", character_num, word_num, line_num);


	// 풀이 코드
	char c;
	int n_chars = 0;	// number of non-space characters
	int n_words = 0;
	int n_lines = 0;
	bool word_flag = false;
	bool line_flag = false;

	printf("Enter text : \n");

	while ((c = getchar()) != STOP) {
		// count character numbers
		if (!isspace(c)) {
			n_chars++;	// count non-space characters
		}

		// count word numbers
		if (!isspace(c) && !word_flag) {
			n_words++;
			word_flag = true;
		}

		if (isspace(c)) {
			word_flag = false;
		}

		// count line numbers
		if (!isspace(c) && !line_flag) {
			n_lines++;
			line_flag = true;
		}

		if (c == '\n') {
			line_flag = false;
		}
	}

	printf("Characters = %d, Words = %d, Lines = %d\n", n_chars, n_words, n_lines);

	return 0;
}