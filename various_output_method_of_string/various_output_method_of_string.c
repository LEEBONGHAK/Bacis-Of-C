﻿#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define TEST "A string from #define"

/*
	puts() which doesn't add a new line at the end
	Use pointer increment operator and putchar()
*/
void custom_put(const char* str);	// Only two lines
int custom_put2(const char* str);	// Add '\n', return # of characters

int main() {
	/*
		puts() : add '\n' at the end
	*/
	char str[60] = "STring array initialized";
	const char* ptr = "A pointer initialized";

	puts("String without \\n");
	puts("END");
	puts(TEST);
	puts(TEST + 5);
	puts(&str[3]);
	//puts(str[3]);		// Error
	puts(ptr + 3);
	printf("\n");


	/*
		string without '\0'
	*/
	char str1[] = { 'H','I','!' };		// No '\0' at the end.
	puts(str1);		// VS warns you!
	printf("\n");


	/* puts() and fputs() */
	char line[100];
	while (gets(line)) {		// while (gets(line) != NULL)
		puts(line);
	}

	/*char line[100];
	while (fgets(line, 100, stdin)) {
		fputs(line, stdout);
	}*/


	/*
		printf()
	*/
	char str2[] = "Just do it, do it!";
	printf("%s\n", str2);		// '\n' added
	puts(str2);

	char input[100] = "";
	int ret = scanf("%10s", input);		// Input : "Just do it, do it!\n" (Note %10s)
	printf("%s\n", input);				// Output : "Just"
	ret = scanf("10%s", input);			// Reads remaing buffer
	printf("%s\n", input);				// Output : "do"


	/*
		Custom function 
	*/
	custom_put("Just ");
	custom_put("Do it!");

	printf("%d\n", custom_put2("12345"));

	return 0;
}

void custom_put(const char* str) {
	while (*str != '\0') {		// while(*str)
		putchar(*str++);
	}
}

int custom_put2(const char* str) {
	int count = 0;

	while (*str) {
		putchar(*str++);
		count++;
	}
	putchar('\n');

	return count;
}