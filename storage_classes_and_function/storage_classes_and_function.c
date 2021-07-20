#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

/*
	Storage Classes and Functions
	- Functions external (by default) or static
	- A function declaration is assumed to be extern
*/

int g_int;		// defining declaration

//extern void fun();
void fun();

//extern void fun_two();
void fun_two();

int main() {
	fun();
	fun_two();

	return 0;
}

void fun() {
	extern int g_int;		// optional

	g_int += 1;
	printf("g_int in fun_two() %d %p\n", g_int, &g_int);
}