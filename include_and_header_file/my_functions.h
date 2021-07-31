#pragma once	// 헤더가드 (header guard)

/* 
	[헤더가드(header guard)가 없는 경우 중복 include 예시]
	
	A.h를 B.h가 include하고 main.c에서 A.h와 B.h를
	모두 include한다면 main.c에서는 A.h가 B.h를 통해서
	한 번 더 include되는 형태가 됨
	=> 헤더가드가 이러한 예시를 방지해줌
	
	* 헤더가드는 인클루드 가드(include guard)라고도 불린다.
*/

//#ifndef __MY_FUNCTIONS__		// 이전 header guard를 하기 위한 방식
//#define __MY_FUNCTIONS__

extern int status;

static int si = 0;

extern int add(int a, int b);

static int multiply(int a, int b) {
	return a * b;
}

//int subtract(int a, int b)
inline int subtract(int a, int b) {
	return a - b;
}

void print_status();
void print_address();

//#endif