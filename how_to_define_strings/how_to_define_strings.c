#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MESSAGE "A symbolic string contant"
#define MAXLENGTH 81

int main() {
	char words[MAXLENGTH] = "A string in an array";	// 배열은 읽기 / 쓰기가 모두 가능한 메모리를 사용
	const char* pt1 = "A pointer to a string";		// 문자열 리터럴은 프로그램의 일부이기 때문에 읽기 전용 메모리에 저장되어 있음

	puts("Puts() adds a new line at the end:");		// puts() add \n at the end
	puts(MESSAGE);
	puts(words);		// char words[21] removes this warning - 즉, 오버된 부분이 초기화되지 않아 warning
	puts(pt1);
	words[3] = 'p';		// OK
	puts(words);
	//pt1[8] = 'A';		// Runtime Error - 읽기 전용 메모리에 저장된 데이터의 값을 바꾸려고 시도하면 운영체제가 중단시킴 (따라서 const를 이용해 컴파일 에러를 일으켜 방지)
	

	char greeting[50] = "Hello, and"" How are" " you"
		" today!";
	//char greeting[50] = "Hello, and How are you today!";

	puts(greeting);


	printf("\"To be, or not to be\" Hamlet said.\n");

	printf("%s, %p, %c\n", "We", "are", *"excellent programmers");


	const char m1[15] = "Love you!";
	for (int i = 0; i < 15; ++i) {
		printf("%d ", (int)m1[i]);	// Note the null characters
	}
	printf("\n");


	const char m2[15] = { 'L','o','v','e',' ','y','o','u','!','\0' };
	for (int i = 0; i < 15; ++i) {
		printf("%d ", (int)m2[i]);	// Note the null characters
	}
	printf("\n");

	const char m3[] = "Love you, too!";


	int n = 8;
	char cookies[1] = { 'A' };
	char cakes[2 + 5] = { 'A', };
	char pies[2 * sizeof(long double) + 1] = { 'A', };
	//char crumb[n];		// VLA
	

	char truth[10] = "Truths is ";
	if (truth == &truth[0]) puts("true!");
	if (*truth == 'T') puts("true!");
	if (*(truth + 1) == truth[1]) puts("true!");
	if (truth[1] == 'r') puts("true!");
	
	
	return 0;
}