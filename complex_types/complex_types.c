#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <complex.h>

int main() {
	_Dcomplex z; // double type complex
	z._Val[0] = 1.0;
	z._Val[1] = 1.0;

	/* gcc의 경우
	// double _Imaginary i = 3; => gcc에도 허수부 구현이 안되있음
	double _Complex z = 1 + 2*I;

	z = 1 / z;

	printf("1 / (1.0 + 2.0i) = %.1f%+.1fi\n", creal(z), cimag(z));	
	*/


	return 0;
}