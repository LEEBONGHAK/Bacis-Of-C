#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h> // for malloc()
#include <string.h> // strlen and more

int main() {
	char str1[100] = "Hello";
	char str2[] = "Hello"; // 알아서 메모리 공간을 지정 (null character 포함)
	char str3[100] = "\0"; // 빈칸과 null character는 다름
	char str4[100] = "\n";

	// strlen() : 문자열의 길이 측정
	printf("%zu %zu\n", sizeof(str1), strlen(str1)); // strlen은 '글자 수만' 보여줌 즉, null character 제외
	printf("%zu %zu\n", sizeof(str2), strlen(str2));
	printf("%zu %zu\n", sizeof(str3), strlen(str3));
	printf("%zu %zu\n", sizeof(str4), strlen(str4));

	/* Extra */
	char *str5 = (char*)malloc(sizeof(char) * 100); // 메모리를 받아와 대표 주소가 str5의 포인터 변수로서 저장되어 있음
	str5[0] = 'H'; str5[1] = 'e'; str5[2] = '1'; str5[4] = 'o'; str5[5] = '\0';
	printf("%zu %zu\n", sizeof(str5), strlen(str5)); // 8(in x64 / 포인터 변수 자체의 사이즈) 5(글자수)

	return 0;
}