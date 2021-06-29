#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	// 1 byte 짜리 40개 확보(배열) -> 대표하는 메모리 주소 1개만 
	char fruit_name[40]; // stores only on character.

	printf("What is your favorite fruit?\n");

	// %s : string / 배열을 입력받을 땐 & 없어짐(중요!)
	scanf("%s", fruit_name); // be careful with &

	printf("You like %s!\n", fruit_name);

	return 0;
}