﻿#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdarg.h>		// Variable Arguments

/*
	Variable Arguments
	- int printf(char const* const _Format,...);

	1. Provide a function prototype using an ellipsis

	void	vaf1(int n, ...);		// OK
	int		vaf2(const char* s, int k, ...);		// OK
	char	vaf3(char c1, ..., char c2);		// Not OK, ellipsis should be the last.
	double	vaf4(...);		// Not OK, no parameter.

	2. Create a va_list type variable in the function definition
	3. Use a macro to initilize the variable to an argument list.
	4. Use a macro to access the argument list.
*/

double average(int, ...);
double average2(char* format_string, ...);

int main() {
	double a, b, c, d;

	a = average(3, 1.1, 2.2, 3.3);
	b = average(6, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6);
	c = average2("dd", 1.1, 2.2, 3.3);
	d = average2("ddd", 1.1, 2.2, 3.3, 4.4, 5.5, 6.6);


	printf("%lf\n", a);
	printf("%lf\n\n", b);

	printf("%lf %lf\n", c, d);		// printf() 가 이러한 방식으로 여러 parameter들을 받을 수 있음

	return 0;
}

double average(int num, ...) {
	va_list ap;
	double sum = 0.0;
	int i;

	va_start(ap, num);
	for (i = 0; i < num; i++) {
		sum += va_arg(ap, double);
	}
	va_end(ap);

	return sum / (double)num;
}

double average2(char* format_string, ...) {
	int num = strlen(format_string);

	va_list ap;
	double sum = 0.0;
	int i;

	va_start(ap, format_string);
	for (i = 0; i < num; ++i) {
		sum += va_arg(ap, double);
	}
	va_end(ap);

	return sum / (double)num;
}