#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//int a;	// 파일 전체에서 접근이 가능

int int_max(int i, int j);

int int_max(int i, int j) {
	//a = 456;
	int m;			// stack frame
	m = i > j ? i : j;
	
	return m;
}

// 변수가 유효한 영역이 존재한다.
int main() {
	//m = 123;		// error
	
	int a;		

	a = int_max(1, 2);
	printf("%d\n", a);
	printf("%d\n", &a);		// 변수의 주소 출력

	{
		//int a;
		a = int_max(4, 5);
		printf("%d\n", a);
		printf("%d\n", &a);

		int b = 123;
	}

	//b = 456;

	printf("%d\n", a);
	printf("%d\n", &a);

	return 0;
}