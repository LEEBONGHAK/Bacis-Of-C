#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

/*
	Generic selection expression
	- Generic programming : code is not specific to a particular type
	- VS 에서 지원하지 않음

	_Generic : C11 keyword
*/

#define MYTYPE(X) _Generic((X), \
int : (X + 123), \
int : "int", \
int* : "int*", \
float : "float", \
double : "double", \
default : "other"\
)


int main() {
	int d = 5;

	//printf("%d\n", MYTYPE(d));
	printf("%s\n", MYTYPE(d));
	printf("%s\n", MYTYPE(2.0 * d));
	printf("%s\n", MYTYPE(3L));
	printf("%s\n", MYTYPE(&d));

	return 0;
}