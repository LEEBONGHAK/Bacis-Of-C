#define _CRT_SECURE_NO_WARNINGS

// 시스템 마다 다른 메모리 호환성을 유지할 수 있음
#include <stdio.h>
#include <stdint.h> // also included in inttypes.h
#include <inttypes.h> // 대응되는 형식 지정자를 미리 정리해둔 곳

int main() {
	int i;
	int32_t i32;		// 32 bit integer - 32 bit의 메모리를 가짐
	int_least8_t i8;	// smallest 8 bit - 적어도 8 bit를 가지고 있는 타입
	int_fast8_t f8;		// fastest minimum - 8 bit 중 가장 빠른 것
	intmax_t imax;		// biggest signed integers - signed integer중 가장 큰 메모리를 사용
	uintmax_t uimax;	// biggest unsigned integers - unsigned integer중 가장 큰 메모리를 사용

	i32 = 1004;

	printf("me32 = %d\n", i32);
	printf("me32 = %" "d" "\n", i32);
	printf("me32 = %" PRId32 "\n", i32); // 매크로를 사용해서 출력(형식 지정자)

	return 0;
}