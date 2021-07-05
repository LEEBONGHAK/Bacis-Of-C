#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	/* if else */
	int size = 15, cost;

	if (size < 10) {
		goto a;		// label
	}
	goto b;

a: cost = 50 * size;
b: cost = 100 * size;

	if (size < 10) {
		cost = 50 * size;
	}
	//cost = 100 * size;
	else {
		cost = 100 * size;
	}


	/* loop */
	char c;
	
read: c = getchar();
	putchar(c);
	if (c == '.') {
		goto quit;
	}
	goto read;
quit:

	while (1) {
		c = getchar();
		putchar(c);
		if (c == '.') {
			break;
		}
	}

	// 컴퓨터가 일할 때는 goto 문처럼 실행
	// 그러나 사람이 프로그래밍할 때 컴퓨터가 일하는 방식으로 꼭 할 필요는 없다.

	return 0;
}