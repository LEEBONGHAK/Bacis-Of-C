#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>		// printf() in two.c

extern int g_int;		// referencing declaration

static void tool() {	// �ٸ� ������ ���� ���� ���� ���ٰ� �Ǵܵ� ���
	//
}

void fun_two(void) {
//static void fun_two(void) {	// linking error
	
	tool();

	g_int += 1;
	printf("g_int in fun_two() %d %p\n", g_int, &g_int);
}