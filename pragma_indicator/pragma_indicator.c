#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// https://docs.microsoft.com/en-us/cpp/preprocessor/pragma-directives-and-the-pragma-keyword?view=msvc-160

/* 
	#pragma tokens (ex : once) 

	- 컴파일러마다 pragma로 지원되는 내용이 다름
*/

//#pragma pack(1)			// structure의 padding byte 조절
//_Pragma("pack(1)")		// destringizing : remove first and last " and \" -> "	(VS에서 적용 안됨, 의미는 위와 동일)
//#define PACK1 _Pragma("pack(1)")		// macro 만들기
//PACK1

//#pragma warning( disable : 4477 )		// 해당 warning 없애기
//#pragma warning( error : 4477 )		// 해당 warning을 error로 변환

struct s {
	int i;
	char ch;
	double d;
};

int main() {
	struct s A;
	printf("Size of A is %zd\n", sizeof(A));

	return 0;
}