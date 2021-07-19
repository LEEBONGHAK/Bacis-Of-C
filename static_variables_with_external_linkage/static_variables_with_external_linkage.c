#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

/*
	Static variable with external linkage
	- File scope, external linkage, static storage duration
	- External storage class
	- External variable
*/

int g_int;			// 초기화 안해도 되고, 안하면 컴파일러가 알아서 0으로 초기화 (static variable의 경우)
//int g_int = 7;	// 하다못해 0으로 초기화하는 것을 권장
double g_arr[1000] = { 0.0, };
//double g_arr[1000];


/*
	Initializing External Variables
*/
int x = 5;					// ok, constant expression
int y = 1 + 2;				// ok, constant expression
size_t z = sizeof(int);		// ok, sizeof is a constant expression
//int x2 = 2 * x;			// not ok, x is a variable

void func() {
	printf("g_int in main() %d %p\n", g_int, &g_int);
	g_int += 10;
}

void func_sec();

int main() {
	/*
		defining declaration vs referencing declaration
	*/
	//extern int g_int;				// Optional
	//extern int g_int = 1024;		// Error in block scope

	//int g_int = 123;				// hides global g_int

	extern double g_arr[];			// Optional, size is not necessary

	printf("g_int in main() %d %p\n", g_int, &g_int);
	g_int += 1;

	func();
	func_sec();

	return 0;
}