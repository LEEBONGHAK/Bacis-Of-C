#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	int a = 1;
	int int_arr[10] = { 1,2,3,4,5,6,7,8,9 };

	printf("%i %i %i\n", int_arr[0], int_arr[1], int_arr[2]);

	// printf("%i\n", int_arr[10000]); // error

	char c = 'a';
	char str1[10] = "Hello"; // null character(\0) 제외 9글자만 저장 가능
	char str2[10] = { 'H', 'i' };

	printf("%c\n", c);
	printf("%s\n", str1); // 내부적으로 printf가 null character를 만나게 되면 더 이상 출력을 하지 않음
	printf("%s\n", str2);

	printf("%hhi %hhi %hhi %hhi %hhi\n", str2[0], str2[1], str2[2], str2[3], str2[4]);

	// char str3[10] = "Hello, World"; // array size is not enough (초기화된 값은 null포함 13글자)
	char str3[20] = "Hello, World";
	printf("%s\n", str3); // Hello, World
	char str4[20] = "Hello, \0World";
	printf("%s\n", str4); // Hello, (중간에 null character 때문에 뒷부분 무시, 그러나 뒷부분의 데이터가 없어지는 것은 아님)

	return 0;
}