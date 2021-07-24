#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// Enumerated Types : 정수형 상수가 마치 이름이 있는 것처럼 도와주는 것

/* Motivation
int c = 0;		// red : 0, orange : 1, yellow : 2, green : 3, ...
if (c == 2) {
	printf("yellow");
}
... ...
*/

/*
#define RED		1
#define ORANGE	2
#define YELLOW	3

int c = YELLOW;
if (c == YELLOW) {
	printf("yellow");
}
... ...
*/

int main() {
	/*
		Enumerated type
		- Symbolic names to represent integer constants
		- Improve readability and make it easy to maintain
		- enum-specifier (struct-specifier, union-specifier)

		Enumerators
		- The symbolic constants
	*/
	enum spectrum { red, orange, yellow, green, blue, violet };
	//				0	 1		 2		 3		4	  5

	enum spectrum color;
	color = blue;
	if (color == yellow) {
		printf("yellow\n\n");		// Note: enumerator are not strings
	}


	for (color = red; color <= violet; color++) {		// Note: ++ operator doesn't allowed in C++, use type int
		printf("%d ", color);
	}
	printf("\n");


	printf("red = %d, orange = %d\n\n", red, orange);


	enum kids { jackjack, dash, snoopy, nano, pitz };
	// nano has a value of 3
	enum kids my_kid = nano;
	printf("nano %d %d\n\n", my_kid, nano);

	
	enum levels { low = 100, medium = 500, high = 2000 };

	int score = 800;
	if (score > high) {
		printf("High score!\n");
	}
	else if (score > medium) {
		printf("Good job\n");
	}
	else if (score > low) {
		printf("Not bad\n");
	}
	else {
		printf("Do your best\n");
	}
	printf("\n");

	
	enum pet { cat, dog = 10, lion, tiger };
	// lion has a value of 11
	printf("cat %d\n", cat);
	printf("lion %d\n", lion);


	return 0;
}