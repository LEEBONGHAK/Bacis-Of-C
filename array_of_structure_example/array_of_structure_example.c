#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#define MAX_TITLE 40
#define MAX_AUTHOR 40
#define MAX_BOOKs 3		// maximum number of books

struct book {
	char title[MAX_TITLE];
	char author[MAX_AUTHOR];
	float price;
};

char* s_gets(char* st, int n);		// 문자열 입력 받는 함수

int main() {
	/* array of book structrues */
	struct book library[MAX_BOOKs] = { {"Empty", "Empty", 0.0f}, };

	int count = 0;

	while (1) {
		// input title
		printf("Input a book title or press [Enter] to stop.\n>> ");
		s_gets(library[count].title, MAX_BOOKs);

		// break if the first character of the input title is '\0'
		if (library[count].title[0] == '\0')
			break;

		// input author name
		printf("Input the author.\n>> ");
		s_gets(library[count].author, MAX_AUTHOR);

		// input price
		printf("Input the price.\n>> ");
		scanf("%f", &library[count].price);

		while (getchar() != '\n') {		// clear buffer
			continue;
		}

		count++;

		if (count == MAX_BOOKs) {
			printf("No more books\n");
			break;
		}
	}

	if (count > 0) {
		printf("\nThe list of books:\n");
		for (int index = 0; index < count; index++) {
			printf("\"%s\" written by %s: %.1f\n",
				library[index].title, library[index].author, library[index].price);
		}
	}
	else {
		printf("No books to show\n");
	}

	return 0;
}

char* s_gets(char* st, int n) {
	char* ret_val;
	char* find;

	ret_val = fgets(st, n, stdin);		// vs.scanf()
	if (ret_val) {
		find = strchr(st, '\n');		// look for newline
		if (find) {						// if the address is not NULL
			*find = '\0';				// place a null character there
		}
		else {
			while (getchar() != '\n') {
				continue;				// dispose of rest of line
			}
		}
	}

	return ret_val;
}