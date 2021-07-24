#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <ctype.h>		// toupper(), tolower()

void ToUpper(char* str);
void ToLower(char* str);
void UpdateString(char* str, int(*pf)(int)); // 기능을 수행할 함수를 포인터를 이용해 인수로 받고 있음 -> 위의 두 함수를 합칠 수 있음

int main() {
	char str[] = "Hello, World!";

	void (*pf)(char*);
	
	pf = ToUpper;			// Name of function is a pointer
	//pf = &ToUpper;		// Acceptable
	//pf = ToUpper(str);	// Not acceptible in C

	printf("String literal %lld\n", (long long)("Hello, World!"));
	printf("Function pointer %lld\n", (long long)ToUpper);
	printf("Variable %lld\n", (long long)str);
	printf("\n");

	(*pf)(str);				// ToUpper(str);
	//pf(str);				// K&R X, ANSI Ok

	printf("ToUpper %s\n", str);

	pf = ToLower;
	pf(str);

	printf("ToUpper %s\n\n", str);



	/* passing function pointers to functions */
	UpdateString(str, toupper);
	printf("ToUpper %s\n", str);

	UpdateString(str, tolower);
	printf("ToUpper %s\n\n", str);

	// Note: __cdecl is function calling convention

	return 0;
}

void ToUpper(char* str) {
	while (*str) {
		*str = toupper(*str);
		str++;
	}
}

void ToLower(char* str) {
	while (*str) {
		*str = tolower(*str);
		str++;
	}
}

// 기능을 수행할 함수를 포인터를 이용해 인수로 받고 있음 -> 위의 두 함수를 합칠 수 있음
void UpdateString(char* str, int (*pf)(int)) {
//void UpdateString(char* str, int (__cdecl *pf)(int)) {		// 똑같이 선언 가능
	while (*str) {
		*str = (*pf)(*str);
		str++;
	}
}