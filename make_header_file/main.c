#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>		// 함수의 정의가 만든 헤더 파일에 포함되어 있다면 없어도 됨
#include "my_print_functions.h"

int main() {
	print_hello();
	print_hi();
	print_hello();
	print_hi();
	print_str("No one lives forever.");
	print_str("Valar morghulis");

	printf("Hello\n");

	return 0;
}

/*
	헤더 파일(header file) 만들기
	
	1. 일반적으로 main()이 존재하는 파일명이 main.c로 지정되어 있음
	2. 프로젝트에서 우클릭-add-new item-header 파일 추가
	3. 같은 이름의 c 파일을 만들어 함수의 정의를 하고, 헤더 파일에 선언만 남겨 목차처럼 사용하는 편
*/