#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void temp(register int r) {
	// do something with r
}

int main() {
	register int r;		// 컴파일러에게 변수가 가급적 register에 위치하도록 요청하는 정도 - 따라서, 항상 register에 위치하는 것이 아님 
	r = 123;

	// register의 경우 주소 호출 불가
	//printf("%p\n", r);
	//int* ptr = &r;	

	// 'register double'의 경우 컴파일러에 따라 컴파일러가 안될 수도 있음

	return 0;
}