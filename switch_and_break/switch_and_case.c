#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	char c;
	while ((c = getchar()) != '.') {
		printf("You love ");

		switch (c) {	// Note : integer types only
		case 'a':
		case 'A':
			printf("apple");
			break;
		case 'b':
		case 'B':
			printf("baseball");
			break;
		case 'c':
		case 'C':
			printf("cake");
			break;
		default:
			printf("nothing");
		}

		printf(".\n");

		while (getchar() != '\n') {	// 첫 글자를 제외하고 같은 줄의 다른 글자들을 줄바꿈 전까지 무시
			continue;
		}
	}

	return 0;
}