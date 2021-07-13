#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	/* Pointer Compatibility */
	int n = 5;
	double x;
	x = n;		// no error
	int* p1 = &n;
	double* pd = &x;
	//pd = p1;	// Warning
	pd = (double*)p1;	// 올바른 표현 - 잘 쓰이진 않음

	int* pt;
	int(*pa)[3];
	int ar1[2][3] = { 3, };
	int ar2[3][2] = { 7, };
	int** p2;		// a pointer to a pointer

	pt = &ar1[0][0];	// pointer-to-int

	for (int i = 0; i < 6; ++i) {
		printf("%d ", *(pt + i));
	}
	printf("\n");

	pt = ar1[0];		// pointer-to-int
	//pt = ar1;			// Warning (Error)

	pa = ar1;			// pointer-to-int[3]
	//pa = ar2;			// Warning or error

	p2 = &pt;			// pointer-to-int *
	*p2 = ar2[0];		// pointer-to-int	'pt = ar1[0];' 과 비슷한 상황
	//p2 = ar2;			// Warning (Error)
	
	/*
		Notes (중요 !)
		- p2: pointer to pointer to int
		- ar2: a pointer to array-of-2-ints
	*/


	/* Pointer and const */
	int x1 = 20;
	const int y = 23;
	int* p3 = &x1;
	const int* p4 = &y;
	const int** pp2 = &p3;
	//p3 = p4;		// Warning (Error) - 대입은 되지만 좋은 사례는 아님

	//*p4 = 123;	// Error
	p4 = p3;		// const int* const p2 = &y; 하면 안됨 - 지금은 indirection을 했을 때 못바꾼다는 의미이기 때문에 가능

	int x2 = 30;
	int* p5 = &x2;
	*pp2 = p5;
	pp2 = &p3;

	{
		const int** pp2;
		int* p1;
		const int n = 13;
		pp2 = &p1;		// const?
		*pp2 = &n;		// sets p1 to pointer at n
		*p1 = 10;		// change n
		// no error - 컴파일러마다 차이가 있으며, 하지 않는 것이 좋음
	}


	/* C const and C++ const */
	// C++에서는 보다 엄격하게 막음 - 사용하지 않는 것이 바람직함
	{
		const int y;
		const int* p2 = &y;
		//int* p1;
		//p1 = p2;	// Warning (error in cpp)
	}

	return 0;
}