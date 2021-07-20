#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>		// memcpy
#include "constants.h"

/*
	global constants
	- make global variables with const
	- or make header file
*/
//const double grabity = 9.8;
//const double PI = 3.141592;

int main() {
	/*
		Qulified types
		const, volatile, restrict, _Atomic
	*/


	/* const */
	// C99 ideompotent - 여러개 사용해도 괜찮
	const const const int n = 6;		// const int n = 6;

	typedef const int zip;	// zip이란 이름으로 프로그래머가 커스텀 type 생성
	const zip q = 8;		// const const int zip


	//const int i;			// Not initialized!
	//i = 12;				// Error
	//printf("%d\n", i);	// Error

	const int j = 123;		// const를 사용할 때는 초기화를 해야한다.
	const int arr[] = { 1,2,3 };


	float f1 = 3.14f, f2 = 1.2f;

	const float* pf1 = &f1;
	//*pf1 = 5.0f;		// Error
	pf1 = &f2;			// Allowed

	float* const pf2 = &f1;		// look 'const' location
	*pf2 = 6.0f;		// Allowed
	//pf2 = &f2;		// Error

	const float* const pf3 = &f1;
	//*pf3 = 7.0f;		// Error
	//pf3 = *pf2;		// Error


	/*
		volatile (휘발성)
		- Do not optimize -> 컴파일러야 너가 최적화하지 마라ㅏ
		- (ex: hardward clock)
	*/
	volatile int vi = 1;		// volatile location - 컴파일러가 모르는 상황에서 값이 바뀔 수 있음
	volatile int* pvi = &vi;	// points to a volatile location

	int i1 = vi;

	// ...

	int i2 = vi;


	/*
		restrict (__restrict in VS) 
		- sole initial means of accessing a data object -> data object에 접근하는게 하나뿐이다
		- compiler can't check this restriction -> 컴파일러가 restrict가 지켜지고 있는지 알 수 없음
	*/
	int ar[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int* par = ar;

	int* __restrict restar = (int*)malloc(10 * sizeof(int));
	if (!restar) {
		exit(1);
	}

	ar[0] += 3;
	par[0] += 5;
	//par[0] += 8;			// 같은 걸 지칭해도 이름이 다르니까 이러한 최적화 불가능

	restar[0] += 3;
	restar[0] += 5;
	//restar[0] += 8;		// Equalivalent - 최적화를 해줄 수도 있다ㅏ (최적화 도와줌)

	free(restar);

	return 0;
}