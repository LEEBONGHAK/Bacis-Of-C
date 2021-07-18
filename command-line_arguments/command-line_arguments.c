#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// CUI를 이용해 실행할 때 argument를 받을 수 있음
int main(int argc, char* argv[]) {
	int count;

	printf("The command line has %d arguments:\n", argc);

	for (count = 0; count < argc; count++) {
		printf("Arg %d : %s\n", count, argv[count]);
	}
	printf("\n");

	return 0;
}