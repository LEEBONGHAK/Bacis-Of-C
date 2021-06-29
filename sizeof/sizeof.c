#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h> // malloc()

struct MyStruct {
	int i; // 4 bytes
	float f; // 4 bytes
};

int main() {
	/* 1. sizeof basic types */

	// sizeof : 자료형이 차지하는 메모리의 크기(byte)를 알려줌
	int a = 0;
	unsigned int int_size1 = sizeof a; // 자료형이 선언이 된 변수명을 통해 방법 1
	unsigned int int_size2 = sizeof(int); // 자료형을 직접 입력
	unsigned int int_size3 = sizeof(a); // 자료형이 선언이 된 변수명을 통해 방법 2

	size_t int_size4 = sizeof(a); // typedef unsigned int size_t => 이식성을 높이기 위해 사용
	size_t float_size = sizeof(float);

	printf("Size of int type is %u bytes.\n", int_size1);
	printf("Size of int type is %zu bytes.\n", int_size4);
	printf("Size of float type is %zu bytes.\n", float_size);


	/* 2. sizeof arrays */

	int int_arr[30]; // int_arr[0] = 1024; ...
	int *int_ptr = NULL; // pointer
	int_ptr = (int*)malloc(sizeof(int) * 30); // int_ptr[0] = 1024; ...

	printf("Size of array = %zu bytes\n", sizeof(int_arr)); // 배열의 메모리 사이즈(120 bytes)
	printf("Size of pointer = %zu bytes\n", sizeof(int_ptr)); // 배열을 대표하는 메모리 주소의 사이즈(8 bytes)


	/* 3. sizeof character array */

	char c = 'a';
	char string[10]; // maximally 9 character + '/0' (null character)

	size_t char_size = sizeof(char);
	size_t str_size = sizeof(string);

	printf("Size of char = %zu bytes\n", char_size); // 1 byte
	printf("Size of string type = %zu bytes\n", str_size);  // 10 bytes


	/* 4. sizeof structure */

	printf("%zu\n", sizeof(struct MyStruct)); // 8

	return 0;
}