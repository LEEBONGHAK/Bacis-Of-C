#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <time.h>		// time()

int main() {
	/*
		typedef specifier
		- Give symbolic names (or aliases) to types
		- Does not create new types. 
	*/
	typedef unsigned char BYTE;			// Note the scope of BYTE

	BYTE x, y[10] = { 0, }, * z = &x;
	
	{
		typedef unsigned char byte;		// You can use lowercases as well;


		/* Portable data types - 이식성이 높은 데이터 타입 */
		size_t s = sizeof(byte);		// unsigned int (x86), unsigend long long (x64)
		// unsigned int s = sizeof(byte);		// x86
		// unsigned long long s = sizeof(byte);		// x64
	}

	//byte b;		// typedef definition has a scope



	/*
		This function returns the time since 00:00:00 UTC, January 1, 1970 (Unix timestamp)
		in seconds.
	*/
	time_t t = time(NULL);
	printf("%lld\n\n", t);



	/* 
		typedef vs #define
		
		- typedef interpretation is performed by the compiler, not the preprocessor
		- More flexible than #define
	*/
	typedef char* STRING;

	STRING name = "John Wick", sign = "World";

	/*
	#define STRING char*

	STRING name, sign;		// 전처리기(preprocessor)에 의해 아래처럼 해석됨
	char* name, sign;		// Note the type of sign (이 경우 sign은 'char*'이 아닌 'char'이 됨)
	*/



	typedef struct complex {
		float real;
		float imag;
	} COMPLEX;		// typedef struct complex COMPLEX

	typedef struct { double width; double height; } rect;		// No tag
	rect r1 = { 1.1,2.2 };
	rect r2 = r1;

	printf("%f %f\n\n", r2.width, r2.height);

	return 0;
}