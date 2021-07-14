#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	/* Arrays of Character Strings */
	const char* mythings[5] = {		// 메모리에 1개만 존재 - 메모리를 아낄 수 있지만 바꿀 수 없음
		"Dancing in the rain",
		"Counting apples",
		"Watching movies with friends",
		"Writing sad letters",
		"Studying the C language",
	};

	char yourthings[5][40] = {		// 메모리에 2개만 존재
		"Studying the C++ language",
		"Eating",
		"Watching Netflix",
		"Walking around till dark",
		"Deleting spam emails"
	};

	const char* temp1 = "Dancing in the rain";
	const char* temp2 = "Studying the C++ language";

	printf("%s %u %u\n", mythings[0], (unsigned)mythings[0], (unsigned)temp1);
	printf("%s %u %u\n", yourthings[0], (unsigned)yourthings[0], (unsigned)temp2);
	//printf("%u %u\n", (unsigned)yourthings[0][0], (unsigned)temp2);
	printf("\n");


	printf("%-30s %-30s\n", "My Things:", "Your Things");
	for (int i = 0; i < 5; i++) {
		printf("%-30s %-30s\n", mythings[i], yourthings[i]);
	}


	printf("\nsizeof mythings: %zd, sizeof your yourthings: %zd\n\n",
		sizeof(mythings), sizeof(yourthings));


	// Not a good idea to take advantage of this property
	for (int i = 0; i < 100; i++) {
		printf("%c", mythings[0][i]);
	}
	printf("\n\n");

	for (int i = 0; i < 200; i++) {
		printf("%d", (int)yourthings[0][i]);
	}
	printf("\n\n");

	for (int i = 0; i < 200; i++) {
		printf("%c", yourthings[0][i]);
	}
	printf("\n\n");


	return 0;
}