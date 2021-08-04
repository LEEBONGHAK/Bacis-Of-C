#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include <stdlib.h>		// standard utility library

/*
	rand(), srand(), malloc(), free(), ...
*/

void goodbye(void) {
	printf("Goodbye\n");
}

void thankyou(void) {
	printf("Thankyou\n");
}

int main() {
	printf("Purchased?\n");
	if (getchar() == 'y')
		atexit(thankyou);		// atexit() : 프로그램이 종료될 때 어떤 함수를 호출할지 등록

	while (getchar() != '\n') {};

	printf("Goodbye message?\n");
	if (getchar() == 'y')
		atexit(goodbye);


	/* 
		exit(0) - 문제가 있는 지 확인할 때 많이 사용 
		
	// This is not allowed in VS
	#include <stdlib.h>
	#include <stdio.h>
	#include <stdnoreturn.h>

	// causes undefined behavior if i <= 0
	// exits if i > 0
	_Noreturn void stop_now(int i)		// or _Noreturn void stop_now(int i)	-> _Noreturn : 이 함수가 끝나고 프로그램 종료한다.
	{
		if (i > 0) exit(i);
		//exit(i);
	}

	int main(void)
	{
		puts("Preparing to stop...");
		stop_now(2);
		puts("This code is never executed.");
	}
	*/



	/* qsort(); - 빠른 정렬 */


	return 0;
}