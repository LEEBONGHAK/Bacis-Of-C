#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "DifferentFile.h"

void different_function();

int main() {
	printf("__FILE__ : %s\n", __FILE__);		// 매크로가 사용된 파일의 이름을 문자열로 변환하여 출력 가능
	printf("__DATE__ : %s\n", __DATE__);		// 컴파일된 날짜
	printf("__TIME__ : %s\n", __TIME__);		// 컴파일된 시간
	printf("__LINE__ : %d\n", __LINE__);		// 코드가 적혀진 줄의 숫자
	printf("__func__ : %s\n", __func__);		// 함수 이름
	printf("\n");

	different_function();

	different_func_in_different_file();



	/* Not defined in VS*/
	/*
	printf("__STDC__ : %d\n", __STDC__);		// comforms to the C standard
	printf("__STDC_HOSTED__ : %d\n", __STDC_HOSTED__);		//hosted vs freestanding implementation KNK p. 330
	printf("__STDC_VERSION__ : %ld\n", __STDC_VERSION__);
	*/

#line 7
	printf("__LINE__ after #line %d\n", __LINE__);

#line 1 "hello.txt"		// 강제로 변환 가능
	printf("__LINE__ after #line %d\n", __LINE__);
	printf("__FILE__ : %s\n", __FILE__);

	printf("\n");


//#if __LINE__ != 39		// 자신만의 에러 메세지를 만들고 싶을 때 사용
//#error Not line 39
//#endif

#if defined(_WIN64) != 1
#error Not WIN64 platform
#endif

//#if __STDC_VERSION__ != 201112L
//#error Not C11
//#endif


	return 0;
}

void different_function() {
	printf("This function is %s\n", __func__);
	printf("This is line %d\n", __LINE__);
	printf("\n");
}