#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// 사용자가 할 수 있는 최대한의 경우의 수를 생각해 인터페이스를 고안해야함
// 같은 기능을 하는 부분이 여러 번 존재할 경우 함수를 사용하는 편이 좋음
int main() {
	int count = 0;

	while (1) {
		printf("Current count is %d. Countinue? (y/n)\n", count);

		int c = getchar();


		if (c == 'n') {
			break;
		}
		else if (c == 'y') {
			count++;
		}
		else {
			printf("Please input y or n\n");
		}
	
		while (getchar() != '\n')
			continue;
	}

	return 0;
}