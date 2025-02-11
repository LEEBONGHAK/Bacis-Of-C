﻿#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	/*
		Object
		- "An object is simply a block of memory that can store a value." (KNK p. 487)
		- Object has more developed meaning in C++ and Object Oriented Programming (OOP)

		Identifiers
		- Names for variables, functions, macros, and other entities. (KNK p. 25)
	*/
	int var_name = 3;		// creates an object called 'var_name'.

	int* pt = &var_name;	// pt is an identifier.
	*pt = 1;				// *pt is not an identifier. *pt designates an object.

	int arr[100];			// arr is an identifier. Is arr an object? -> No
	arr[0] = 7;				// arr[0] is an object


	/*
		L-value is an expression 'referring' to an object (K&R p. 197)

		L-value : left side of an assignment
		R-value : right side, variable, constant, expressions (KNK p. 67)
	*/
	var_name = 3;			// modifiable L-value

	pt = &var_name;
	int* ptr = arr;
	*pt = 7;				// *pt is not an identifier but an modifiable L-value expression

	int* ptr2 = arr + 2 * var_name;		// address R-value
	*(arr + 2 * var_name) = 456;		// L-value expression

	const char* str = "Constant string";		// str is a modifiable L-value
	str = "Second string";						// "Constant string" = "Second string"	// impossible
	//str[0] = 'A';		// Error
	//puts(str);

	char str2[] = "String in an array";
	str2[0] = 'A';		// OK
	//puts(str2)


	/*
		Identifiers have scope.
		Objects have storage duration.
		Variables and functions have one of the following linkages:
			external linkage, internal linkage, or no linkage. 
	*/

	return 0;
}