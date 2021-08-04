#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
//#include "C:\Users\이봉학\Desktop\Basic-Of-C\library\MyLibrary.h"		// 절대 경로 사용법
#include <MyLibrary.h>		// project properties - C/C++ - general - additional include directories 에 헤더 파일 전 절대 경로를 복붙하여 사용

/*	
	library linking error 해결법

	1. project properties - Linker - general - additional library directories 에 
	라이브러리가 들어있는 경로 추가
	2. project properties - Linker - input - additional dependencies 에 
	라이브러리 파일명 추가

	- release 모드에서 build할 때는 설정을 잘 맞춰야함
	- release/debug 모드에 따라 헤더 파일은 공통이지만 lib나 dll파일은 다르기 때문
*/

int main() {
	say_hello();
	say_world();

	return 0;
}