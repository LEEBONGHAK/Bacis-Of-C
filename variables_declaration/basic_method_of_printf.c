// standard input output
#include <stdio.h>

int main() {

	// \n (escape sequence) : 줄바꿈 하기
	printf("The truth is ... \nI am Ironman.\n");

	// \" : " 을 출력하고 싶을때 사용(앞에 \을 붙이는 것이 중요)
	printf("\"...\"\n");

	printf("The truth is ... ");
	printf("I am Ironman.\n"); // 붙여서 나옴

	int x, y, z;

	x = 1;
	y = 2;

	z = x + y;

	// %i : integar
	printf("The answer is %i.\n", 7); // 7
	printf("The answer is %i.\n", 1 + 2); // 3
	prinf("% i + % i = %i\n", x, y, z); // 1 + 2 = 3
	// \a : 경고 알람(소리) 출력
	prinf("\a");

	// %d : decimal
	printf("The answer is %d.\n", z); // 3

	return 0;
}