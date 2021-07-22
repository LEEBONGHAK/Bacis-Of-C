#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

void fit_str(char*, unsigned int);
char my_strcat(char* destination, const char* source);
int my_strcmp(const char* standard, const char* compare);

int main() {
	/*
		strlen() : returns length of the string
	*/
	//TODO: use debugger
	char msg[] = "Just,"" do it!";
	puts(msg);
	printf("Length %d\n", strlen(msg));
	fit_str(msg, 4);
	puts(msg);
	printf("Length %d\n\n", strlen(msg));


	/*
		strcat() and strncat() : string concatenation
	*/
	char str1[100] = "First string";
	char str2[] = "Second string";

	strcat(str1, ", ");
	strcat(str1, str2);
	//strncat(str1, str2, 2);	// Append 2 characters
	//my_strcat(str1, str2);
	puts(str1);
	printf("\n");
	//TODO: check my_strcat()


	/*
		strcmp() and strncmp() : compare strings (not characters)
	*/
	printf("%d\n", strcmp("A", "A"));
	printf("%d\n", strcmp("A", "B"));
	printf("%d\n", strcmp("B", "A"));
	printf("%d\n", strcmp("Hello", "Hello"));
	printf("%d\n", strcmp("Banana", "Bananas"));
	printf("%d\n", strcmp("Bananas", "Banana"));
	printf("%d\n", strncmp("Bananas", "Banana", 6));
	printf("\n");
	//TODO: check my_strcmp()


	/*
		strcpy() and strncpy() : 포인터만 복사하는 것이 아닌 내용물 하나하나를 복사 -> 같은 곳에 여러번 쓸 경우 덮어써짐
	*/
	char dest[100] = "";		// make sure memory is enough
	char source[] = "Start programming!";
	//dest = source;			// Error
	//dest = "Start something";	// Error
	strcpy(dest, source);
	puts(dest);

	// add that the number of characters to be copied from source
	strncpy(dest, "", 15);
	strncpy(dest, source, 5);	// '\0' is Not added
	puts(dest);

	strcpy(dest, source + 6);
	puts(dest);

	strcpy(dest, source);
	puts(dest);

	strcpy(dest, source);
	puts(dest);

	strcpy(dest + 6, "coding!");
	puts(dest);
	printf("\n");


	/*
		sprintf()
	*/
	char str[100] = "";
	int i = 123;
	double d = 3.14;
	sprintf(str, "%05d.png %f", i, d);
	puts(str);
	// capture0000.png, capture0001.png, ... - 이런식의 표현이 필요할 때 사용 
	printf("\n");


	/*
		There are more functions...
	*/
	printf("%s\n", strchr("Hello, World", 'W'));

	printf("%s\n", strpbrk("Hello, World", "ABCDE"));
	printf("%s\n", strpbrk("Hello, World", "abcde"));

	printf("%s\n", strrchr("Hello, World, Hello, World", 'l'));		// last occurrence

	printf("%s\n", strstr("Hello, World", "wor"));
	printf("%s\n", strstr("Hello, World", "Wor"));


	return 0;
}

void fit_str(char* str, unsigned int size) {
	if (strlen(str) > size) {
		str[size] = '\0';
	}
}

// Function to implement strcat() function in C
char my_strcat(char* destination, const char* source) {
	// make ptr point to the end of the destination string
	char* ptr = destination + strlen(destination);

	// Appends characters of source to the destination string
	while (*source != '\0') {
		*ptr++ = *source++;
	}

	// null terminate destination string
	*ptr = '\0';
	
	// destination is retruned by started strcat()
	return destination;
}

// Function to implement strcmp() function in C
int my_strcmp(const char* standard, const char* compare) {
	//my code
	//int num_std = 0;
	//int num_com = 0;
	//
	//while (*standard != '\0') {
	//	num_std = (int)*standard;
	//	*standard++;
	//}

	//while (*compare != '\0') {
	//	num_com = (int)*compare;
	//	*compare++;
	//}

	//if (num_std == num_com) {
	//	return 0;
	//}
	//else if (num_std > num_com){
	//	return 1;
	//}
	//else {
	//	return -1;
	//}


	// in stack overflow
	while (*standard && (*standard == *compare)) {
		standard++;
		compare++;
	}
	int i = *standard - *compare;
	
	return i < 0 ? -1 : i > 0 ? 1 : 0;	
}