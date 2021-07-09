#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	char a = 1;
	float b = 3;
	double c = 5;

	char* ptr_a = &a;
	float* ptr_b = &b;
	double* ptr_c = &c;

	a = 2;
	b = 4;
	c = 6;

	printf("%zd %zd %zd\n", sizeof(a), sizeof(b), sizeof(c));					
	printf("%zd %zd %zd\n", sizeof(ptr_a), sizeof(ptr_b), sizeof(ptr_c));		
	printf("%zd %zd %zd\n", sizeof(&a), sizeof(&b), sizeof(&c));				
	printf("%zd %zd %zd\n", sizeof(char*), sizeof(float*), sizeof(double*));	

	/* 
		in x64
	1 4 8	- 메모리 크기
	8 8 8	- 포인터 메모리 크기
	8 8 8	- 주소 크기
	8 8 8	- 주소 크기
	*/

	/*
		in x86
	1 4 8	- 메모리 크기
	4 4 4	- 포인터 메모리 크기
	4 4 4	- 주소 크기
	4 4 4	- 주소 크기
	*/

	return 0;
}