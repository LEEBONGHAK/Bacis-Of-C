#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void display(char cr, int lines, int width);

int main() {
	char c;
	int rows, cols;

	// scanf로 인해 뒤에 숫자까지 모두 입력해야 종료되는 문제 발생
	//while (1) {
	//	scanf("%c %d %d", &c, &rows, &cols);
	//	
	//	while (getchar() != '\n') {
	//		continue;
	//	}
	//	
	//	display(c, rows, cols);
	//	
	//	if (c == '\n') {
	//		break;		// doesn't work well
	//	}
	//}

	
	// getchar와 scanf를 같이 써서 해결
	printf("Input one character and two integers: ");
	while ((c = getchar()) != '\n') {
		scanf("%d %d", &rows, &cols);
		while (getchar() != '\n') {
				continue;
		}

		display(c, rows, cols);
		printf("INput another character and two integers: \n");
		printf("Press Enter to quit.\n");
	}

	return 0;
}

void display(char cr, int lines, int width) {
	for (int i = 0; i < lines; ++i) {
		for (int j = 0; j < width; ++j) {
			putchar(cr);
		}
		putchar('\n');
	}
}