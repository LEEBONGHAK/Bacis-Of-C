﻿#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

/*
	Preprocessor directives begins with # symbol at the beginning of a line.

	Macro
	- An instruction that represents a sequence of instructions in abbreviated form.
*/

/*
	#define			SAY_HELLO			printf("Hello, World!");

	Preprocessor	Macro (name)		body (or replacement list)
	directive

	Macro expansion
*/

/*
	Object-like macros vs Function-like macros

	#define ONE 1				- Object-like macros
	#define SQUARE(X) X * X		- Function-like macros (위험한 부분이 존재)
*/

#define PI 3.141592		// Symbolic, or manifest, constants
#define GRAVITY 9.8


#define THREE 3
#define MESSAGE	"The greatest glory in living lies not in never falling, \
but in rising every time we fall."


#define NINE	  THREE * THREE
#define SAY_HELLO printf("Hello, World!\n");
#define FORMAT	  "Number is %d.\n"


 # define WITH_BLACK 1	// 가능하지만 붙여쓰는 것을 권장


#define MY_CH 'Z'
#define MY_ST "Z"		// Z\0


#define LIMIT 20
const int LIM = 50;
static int arr1[LIMIT];
//static int arr2[LIM];		// clang, C++
const int LIM2 = 2 * LIMIT;
//const int LIM3 = 2 * LIM;	// clang, C++



/*
	Tokens

	#define SIX 3*2
	#define SIX 3 * 2
	#define SIX 3        *          2

	- 컴파일러에 따라 전처리기가 어떻게 해석할지 다름
*/



/* Redefining Constants */
#define SIX 2*3
#define SIX 2*3
//#undef SIX
//#define SIX 2 * 3		// Warning - 전처리기 입장에서 헷갈리며, 다른 의미일 수 있음

int main() {
	int n = THREE;

	SAY_HELLO;		// Note the addintional	;
	n = NINE;
	
	printf(FORMAT, n);
	printf("%s\n", MESSAGE);		// replaced
	printf("SAY_HELLO NINE\n");		// Not replaced


	return 0;
}