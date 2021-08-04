#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include <math.h>		// standard math library
//#include <tgmath.h>		// type generic macros

// Generic Selection Expression - not allowed in VS
/*
#define SQRT(X) _Generic((X),\
 long double: sqrl,\
 float: sqrtf,\
 default: sqrt,\
)
*/

int main() {
	printf("cos(PI) = %f\n\n", cos(3.141592));

	/*
		Pythagorean theorem
		http://en.wikipedia.org/wiki/Pythagorean_theorem
	*/
	double c = 5.0, b = 4.0, a;		// a??
	a = sqrt(c * c - b * b);
	printf("a = %f\n", a);

	float cf = 5.0f, bf = 4.0f, af;
	af = sqrtf(cf * cf - bf * bf);
	printf("a = %f\n\n", af);



	/*	Not allowed in VS
	
	// Type Variants
	double t1 = SQRT(2.0f);
	double t2 = SQRT(2.0);

	if (t1 == t2) {
		printf("Identical\n");
	}
	else {
		printf("Not identical\n");
	}


	// tgmath.h Library
	double a1 = sqrt(2.0f);
	double a2 = sqrt(2.0);

	if (a1 == a2) {
		printf("Identical\n");
	}
	else {
		printf("Not identical\n");
	}
	*/

	return 0;
}