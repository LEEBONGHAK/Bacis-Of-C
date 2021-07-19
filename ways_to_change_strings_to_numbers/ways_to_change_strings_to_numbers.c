#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

// project 오른 클릭 - Properties - Debugging - Command argument 에 argument 입력
// 위의 방식으로도 command-line argument를 적용해 실행 가능
// C 또는 C++ 로 작성된 프로그램을 다른 scripting 언어를 사용하여 실행시킬 때 유용하게 사용됨 (대표적인 scripting 언어 : python)
int main(int argc, char* argv[]) {
	/*
		String to integer, double, long
		atoi(), atof(), atol()

		- decimal only
	*/
	if (argc < 3) {
		printf("Wrong Usage of %s\n", argv[0]);
	}
	else {
		/* Example 1 */
		int times = atoi(argv[1]);
		// atof(), atol()

		for (int i = 0; i < times; i++) {
			puts(argv[2]);
		}
		printf("\n");


		/* Example 2 */
		printf("Sum = %d\n", atoi(argv[1]) + atoi(argv[2]));
		printf("\n");
	}


	/*
		String to long, unsigned long, double
		strtol(), strtoul(), strtod()

		strtod() converts base 10 only
	*/
	char str1[] = "1024Hello";
	char* end;
	long l = strtol(str1, &end, 10);
	printf("%s %ld %s %d\n", str1, l, end, (int)*end);

	char str2[] = "10FFHello";
	long l1 = strtol(str2, &end, 16);
	printf("%s %ld %s %d\n", str2, l1, end, (int)*end);
	printf("\n");

	
	/*
		Numbers to strings
		Use sprintf() instead of _itoa(), _ftoa()
	*/
	char temp[100];
	puts(_itoa(10, temp, 16));	// 10을 16진수로 출력 == 'a'

	sprintf(temp, "%x", 10);
	puts(temp);					// 10을 16진수로 출력 == 'a'


	return 0;
}