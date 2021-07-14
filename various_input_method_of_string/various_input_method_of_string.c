#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define STRLEN 81

char* custom_string_input(char* st, int n);

int main() {
	/* Creating Space */
	//char* name = "";	// Error at RUN-TIME
	char name[128];
	int result = scanf("%s", name);

	/*
		scanf() vs gets()

		scanf() reads one word
		gets reads on line and removes '\n' and add '\0'
	*/


	char words[STRLEN] = "";	// Warning without initialization
	gets(words);				// gets receives pointer. No idea when string ends.
	//gets_s(words, sizeof(words));		// C11 - 최근 gets() 보다 많이 쓰이며, 더 권장됨
	//int result1 = scanf("%s", words);
	printf("START\n");
	printf("%s", words);		// no '\n' at the end
	puts(words);				// puts() adds '\n' at the end
	puts("END.");

	// TODO: try char words[5] => RUN-TIME Error


	/* fgets() and fputs() */
	/* 
		원래 파일 입력을 받을 때 사용하지만 'stdin(standard input)', 
		'stdout(standard output)'을 넣으면 console에서도 사용 가능
	*/
	char words1[STRLEN] = "";
	fgets(words1, STRLEN, stdin);		// does NOT remove '\n'

	// TODO: replace '\n' with '\0'
	int i = 0;
	while (words1[i] != '\n' && words1[i] != '\0') {
		i++;
	}
	if (words1[i] == '\n') {
		words1[i] = '\0';
	}

	fputs(words1, stdout);			// does NOT add '\n'
	fputs("END", stdout);
	printf("\n");


	/* Small array */
	char small_array[5];
	puts("Enter long strings:");
	fgets(small_array, 5, stdin);		// FILE *_Stream
	//printf("%p\n", small_array);
	//printf("%p\n", fgets(small_array, 5, stdin));	// Return value of fgets
	fputs(small_array, stdout);
	printf("\n");


	/* Repeating short reading - buffer를 사용해 한번에 출력되는 것처럼 보이기 */
	char small_array1[5];
	puts("Enter long strings:");
	while (fgets(small_array1, 5, stdin) != NULL && small_array1[0] != '\n') {
		fputs(small_array1, stdout);
		//puts(small_array1);		// What if we use puts() - 버퍼를 이용해 while문 적용
	}


	/* scanf() */
	char str1[6], str2[6];
	int count = scanf("%5s %5s", str1, str2);	// 글자 숫자 제한 가능
	//int count = scanf("%6s %6s", str1, str2);		// run-time error
	//int count = scanf_s("%5s %5s", str1, 6, str2, 6);
	printf("%s|%s \n", str1, str2);


	/* An example of custom input function */
	char word[11];
	puts(custom_string_input(word, 11));


	return 0;
}

char* custom_string_input(char* st, int n) {
	char* ret_ptr;
	int i = 0;

	ret_ptr = fgets(st, n, stdin);
	if (ret_ptr) {
		while (st[i] != '\n' && st[i] != '\0') {
			i++;
		}

		if (st[i] == '\n') {
			st[i] = '\0';
		}
		else {
			while (getchar() != '\n') {		// clear buffer
				continue;
			}
		}
	}

	return ret_ptr;
}
