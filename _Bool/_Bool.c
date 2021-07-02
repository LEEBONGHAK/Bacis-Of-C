#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>	// bool 사용하기

int main() {
	int i;
	i = 5;		// 대입	
	i == 5;		// 비교 -> 그러나 기능을 수행하는 것이 아니기 때문에 warning 발생
	//5 = i;	// literal constant이기 때문에 메모리 공간을 가지고 있지 않아 L-value로 사용 불가 -> error
	5 == i;		// 비교

	while (i = 5) {/* do something */}		// 대입 후 true로 인식된 후 동작됨
	while (i == 5) {/* do something */ }	// 비교

	// C99에 도입됨
	_Bool boolean_true = (2 > 1);
	_Bool boolean_false = (2 < 1);

	printf("True is %d\n", boolean_true);		// 1
	printf("False is %d\n", boolean_false);		// 0

	// 조건 연산자
	printf(boolean_true ? "true" : "false");	// true
	printf("\n");
	printf(boolean_true ? "true" : "false");	// false
	printf("\n");

	
	// C 언어에서는 키워드는 아님 -> 정의된 것 (C++에선 키워드)
	bool bt = true;
	bool bf = false;
	
	printf("True is %d\n", bt);		// 1
	printf("False is %d\n", bf);		//0

	return 0;
}