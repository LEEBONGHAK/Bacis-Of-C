#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	/* continue */
	for (int i = 0; i < 10; ++i) {
		if (i == 5) {
			continue;	// 만나면 뒷 부분이 실행되지 않고 loop 시작
		}

		printf("%d ", i);

		// 동일한 기능
		//if (i != 5) {
		//	printf("%d ", i);
		//}
	}
	//0 1 2 3 4 6 7 8 9
	printf("\n");


	/* break */
	for (int i = 0; i < 10; ++i) {
		if (i == 5) {
			break;	// 만나면 loop 탈출
		}

		printf("%d ", i);
	}
	//0 1 2 3 4
	printf("\n");


	/* while and continue */
	int count = 0;
	while (count < 5) {
		int c = getchar();
		if (c == 'a') {
			continue;
		}
		putchar(c);
		count++;
	}


	/* for and continue */
	for (int count = 0; count < 10; ++count) {
		int c = getchar();
		if (c == 'a') {
			continue;
		}
		putchar(c);
	}


	/* continue as a placeholder */
	// placeholder : 하는 것은 없지만 자리를 차지하고 그곳에 어떤 것이 들어갈 수 있구나 알려주는 것
	while (getchar() != '\n') {
		continue;
	}


	/* Need to use continue? */
	char c;
	while ((c = getchar()) != '\n') {
		if (c == 'a') {
			continue;
		}
		putchar(c);

		// 동일한 기능
		//if (c != 'a') {
		//	putchar(c);
		//}
	}


	/* while and break */
	char c1;
	while ((c1 = getchar()) != '.') {
		putchar(c);
	}
	printf("\n");

	// 동일한 기능 - 더 많이 사용하는 편
	while (1) {
		char c = getchar();

		if (c == '.') {
			break;
		}

		putchar(c);
	}
	printf("\n");


	/* for and break */
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			if (j == 5) {
				break;		// 첫 번째 loop만 탈출
			}
			printf("(%d %d) ", i, j);
		}
		printf("\n");
	}
	printf("\n");

	return 0;
}