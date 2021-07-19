#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>		// printf() in second.c

extern int g_int;		// 방법 1 - file scope에서는 초기화 가능 (그러나 2번 이상 초기화는 불가능)

void temp() {
	//extern int g_int;		// 방법 2 - 단점: block scope에서 초기화 불가능


	g_int += 1000;
}

void func_sec() {
	temp();
	
	//extern int g_int;		// 방법 2 - 단점: block scope에서 초기화 불가능

	g_int += 7;
	printf("g_int in main() %d %p\n", g_int, &g_int);
}