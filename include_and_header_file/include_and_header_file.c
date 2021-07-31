#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "my_functions.h"
#include "my_structures.h"
//#include "my_headers/my_macros.h"	// path -> 절대 경로도 가능 (비추천)
#include "my_macros.h"	// project properties-additional include directories를 이용해 path없이 사용가능
//#include <my_macros.h>		// project properties-additional include directories를 이용하면 ""가 아닌 <>도 가능

/*
	일반적으로,
	내가 만든 것 -> ""로 해더파일 지정
	다른 사람이 만든 것 -> <>로 헤더파일 지정
*/

extern int status;

int main() {
#include "hello_world.h"		
// == printf("Hello, World from a header file\n"); -> 코드 복붙 수준 (통으로 라기엔 보기 힘듬 / 이런 식의 코딩은 너무 좋지 않음)

	printf("\nPI = %f\n\n", PI);

	printf("%p %d\n", &status, status);
	print_status();
	printf("\n");

	printf("%d\n\n", multiply(51, 2));


	// static이기 때문에 둘의 주소가 다름
	printf("main()\n");
	printf("Static function address %p\n", multiply);
	printf("Static variable address %p\n", &si);

	print_address();
	printf("\n");

	return 0;
}