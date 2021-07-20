#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>		// srand()
#include <time.h>		// time()
#include "my_rand.h"

int main() {
	/*
		rand()
		- 0 to RAND_MAX (typically INT_MAX)
		- defined in stdlib.h
	*/

	//srand(1);		// random seed (시작점)
	srand((unsigned int)time(0));	// return 값이 시간에 따라 달라져 random seed가 달라짐
	for (int i = 0; i < 10; ++i) {
		printf("%d\n", rand());
		printf("%d\n", rand() % 6 + 1); // 1 ~ 6 범위
	}
	printf("\n");


	// 내부적으로 사용하는 알고리즘 중 한가지 - 유사 난수 (sudo random number)
	unsigned int next = (unsigned int)time(0);

	for (int i = 0; i < 10; ++i) {
		next = next * 1103515245 + 1234;
		next = (unsigned int)(next / 65536) % 32768;
		printf("%d\n", (int)next);
	}
	printf("\n");


	// in my_rand.c
	my_srand((unsigned int)time(0));
	
	for (int i = 0; i < 10; ++i) {
		//printf("%d\n", my_rand());
		printf("%d\n", my_rand() % 6 + 1);
	}

	return 0;
}