#define _CRT_SECURE_NO_WARNINGS

#include "MyLibrary.h"

#include <stdio.h>

// library를 만들 때 main()가 없음

/* 
	library 설정 : project properties - configuration type - dynamic library 또는 static library

	dynamic library : 프로그램이 실행이 될 때 그때 그때 동적으로 라이브러리를 가져와서 사용
	static library : 프로그램에 라이브러리가 바로 포함이 되는 것

	- debug, release 모드 둘 다 build 하는 것이 좋음
*/

void say_hello() {
	printf("Hello\n");
}

void say_world() {
	printf("World\n");
}