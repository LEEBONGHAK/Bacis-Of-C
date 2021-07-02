#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	int tv, fv;
	tv = (1 < 2);
	fv = (1 > 2);

	printf("True is %d\n", tv);
	printf("False is %d\n", fv);


	// 0 이면 False고, 그 이외엔 True
	int i = -5;
	while (i)
		printf("%d is true\n", i++);
	printf("%d is flase\n", i);

	i = 5;
	while (i)
		printf("%d is true\n", i--);
	printf("%d is flase\n", i);

	// 무한 루프는 서버나 게임 등에서 많이 쓰임, 하지만 최대한 사용하지 않는 것을 권장

	return 0;
}