#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

/*
	Automatic storage duration, block scope, no linkage
	- Automatic storage duration, block scope, no linkage
	- Any variable declared in a block or function header
*/

void func(int k);

int main() {		// Note: main() is a function
	auto int a;		// keyword 'auto' : a storage-class specifier - 없어도 상관 X
	a = 1024;
	
	printf("%d\n", a);		// what happens if uninitialized? - 초기화 X 따라서 Error
	auto int b = a * 3;		// what happens if uninitialized? - warning C4101: 'b': unreferenced local variable (출력을 하지 않으면 warning, 하면 error)
	printf("\n");


	int i = 1;
	int j = 2;

	printf("i %lld\n", (long long)&i);
	{
		int i = 3;		// name hiding
		printf("i %lld\n", (long long)&i);

		int ii = 132;

		// j is visible here
		printf("j = %d\n", j);
	}
	//printf("%d\n", ii);		// ii is not visible here - Error
	printf("i %lld\n", (long long)&i);		// which i? -> int i = 1;
	printf("\n");


	for (int m = 1; m < 2; m++) {
		printf("m %lld\n", (long long)&m);		// no block? - no, it is block
	}

	for (int m = 3; m < 4; m++) {
		printf("m %lld\n", (long long)&m);		// block? - yes, it is block
	}
	printf("\n");


	func(5);	// cannot see any of the variabled defined so far.

	return 0;
}

void func(int k) {
	int i = k * 2;
	// do something with i and k
	printf("i %lld\n", (long long)&i);
}