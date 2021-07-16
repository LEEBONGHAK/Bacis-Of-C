#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>		// getchar(), putchar()

int main() {
	/*
		1. Introduce getchar(), putchar()
		2. Use while loop to process character sequences
		3. Filter a specific cararcter
		4. Convert numbers to asterisks
		5. Lower characters to Upper characters
	*/

	// 1. Introduce getchar(), putchar() 
	char ch;

	//ch = getchar();		// 문자 하나를 가져온다. -> int로 가져옴
	//putchar(ch);		// 한 문자를 출력한다.   -> int로 받아감
	//printf("\n");


	// 2. Use while loop to process character sequences
	//while (ch2 != '\n') {		// Use '\n' to find the end of a sentence
	while ((ch = getchar()) != '\n') {
		putchar(ch);

		// ch = getchar();
	}
	printf("\n\n");


	// 3. Filter a specific cararcter
	while ((ch = getchar()) != '\n') {
		if (ch == 'f' || ch == 'F') {
			ch = 'X';
		}

		/*
		if (ch == 'F') {
			ch = 'X';
		}
		*/

		putchar(ch);
	}
	printf("\n\n");


	// 4. Convert numbers to asterisks
	while ((ch = getchar()) != '\n') {
		//for (int i = 0; i < 10; ++i) {
		//	if (ch == i) {
		//		ch = '*';
		//	}
		//}
		
		if (ch >= '0' && ch <= '9') {	// for문 보다 선호됨
			ch = '*';
		}

		putchar(ch);
	}
	printf("\n\n");


	// 5. Lower characters to Upper characters
	while ((ch = getchar()) != '\n') {
		if (ch >= 'a' && ch <= 'z') {		// 'A' = 65, 'a' = 97
			ch -= 'a' - 'A';
		}
		else if (ch >= 'A' && ch <= 'Z') {
			ch += 'a' - 'A';
		}

		putchar(ch);
	}
	printf("\n\n");

	return 0;
}