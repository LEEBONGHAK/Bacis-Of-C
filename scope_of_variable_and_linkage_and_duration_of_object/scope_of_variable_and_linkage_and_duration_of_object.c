#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

/*
	Variable scopes (visibility)
	- block, function, function prototype, file.
*/
// file scope
int g_i = 123;		// global variable == file scope를 갖는다
int g_j;			// global variable == file scope를 갖는다

void func1() {
	g_i++;			//uses g_i
}

void func2() {
	g_i += 2;		//uses g_i

	//local = 456;	// Error
}

// function prototye scope
void f1(int hello, double world);		// to the end of the prototype declaration
// function prototype 내 변수 생략 가능 [예외] VLA는 길이를 지정해줘야 하기 때문에 프로토타입에서 식별자를 생략할 수 없음 
//void vla_param(int n, int m, double ar[n][m]);	// gcc only

// block scope and function scope
double func_block(double d) {
	double p = 0.0;
	int i;
	for (i = 0; i < 10; i++) {
	//for (int i = 0; i < 10; i++) {	// C99
		double q = d * i;
		p *= q;

		if (i == 5) {
			goto hello;
		}
	}

hello:		// goto 문의 label은 예외로 사용하기 전에 지시 가능
	printf("Hello, World");

	return p;
}


/*
	Linkage

	Variables with block scope, function scope, or function prototype scope
	- No linkage

	File scope variables
	- External or internal linkage
*/
int el;				// file scope with external linkage (global variable)
static int il;		// file scope with internal linkage

void testLinkage();


/*
	Storage duration: - 메모리의 지속기간
	- static storage duration		// 프로그램이 시작될 때 자리잡고 끝날 때까지 유지
	(Note: 'static' keyword indicates the linkage type, not the storage duration)
	- automatic storage duration	// scope에 따라 stack에 저장
	- allocated storage duration	// 동적할당 관련
	- thread storage duration		// 멀치 쓰레딩 관련
*/
// automatic storage duration
void count() {
	int ct = 0;
	printf("count = %d\n", ct);
	ct++;
}

// static storage duration
void static_count() {
	static int ct = 0;
	printf("static count = %d\n", ct);
	ct++;
}

int main() {
	// file scope
	int local = 1234;

	func1();
	func2();

	printf("%d\n", g_i);	// uses g_i
	printf("%d\n", g_j);	// Not initialized? -> no, initialized to 0
	printf("%d\n", local);
	printf("\n");


	// linkage
	el = 1024;

	testLinkage();
	printf("%d\n", el);
	printf("\n");


	// duration
	count();
	count();
	static_count();
	static_count();

	return 0;
}