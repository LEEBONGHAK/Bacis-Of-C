#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	/* struncture of for loop
		for (initialize; test; update) {
			statement
		}	
	*/

	for (int i = 10; i > 0; i--) {
		printf("%d\n", i);
	}

	for (int i = 0; i < 100; i += 8) {
		printf("%d\n", i);
	}

	for (char c = 'A'; c <= 'Z'; c++) {
		printf("%c\n", c);
	}

	for (int i = 0; i * i < 10; i++) {
		printf("%d\n", i);
	}

	for (int x = 1, y = 5; y <= 20; y = (++x * 3) + 10) {
		printf("%d %d\n", x, y);
	}

	for (double d = 100.0; d < 300; d *= 1.5) {
		printf("%f\n", d);
	}


	int i, n;
	n = 2;
	for (i = 2; n < 10; /* left blank */ ) {
		n *= i;
		printf("%d\n", n);
	}

	for (;;) {		// while(1) 과 동일
		printf("I love you!\n");
	}

	int i = 0;
	// 입력한 숫자가 7이 아니라면 계속 실행
	// 권장하는 방법은 아님
	for (printf("Let's go!\n"); i != 7; scanf("%d", &i)) {
		;			// null statement
	}

	return 0;
}