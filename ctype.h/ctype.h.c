#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <ctype.h>		// isalpha() and more

int main() {
	char ch;

	// 대문자 <-> 소문자 변환 예제
	while ((ch = getchar()) != '\n') {
		//if (ch >= 'a' && ch <= 'z') {		// 'A' = 65, 'a' = 97
		//	ch -= 'a' - 'A';
		//}
		//else if (ch >= 'A' && ch <= 'Z') {
		//	ch += 'a' - 'A';
		//}

		if (islower(ch)) {
			ch = toupper(ch);
		}
		else if (isupper(ch)) {
			ch = tolower(ch);
		}

		putchar(ch);
	}
	printf("\n\n");


	// 숫자 -> * 변환 예제
	while ((ch = getchar()) != '\n') {
		if (isdigit(ch)) {
			ch = '*';
		}

		putchar(ch);
	}
	printf("\n\n");

	// ref : tutorialpoint에서 ctype.h 검색

	return 0;
}