#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>		// printf() in two.c

extern int g_int;		// referencing declaration

static void tool() {	// 다른 곳에서 쓰일 일이 전혀 없다고 판단된 경우
	//
}

void fun_two(void) {
//static void fun_two(void) {	// linking error
	
	tool();

	g_int += 1;
	printf("g_int in fun_two() %d %p\n", g_int, &g_int);
}