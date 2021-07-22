#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>		// strlen(), strcmp()
#include <stdlib.h>		// malloc(), free()

#define SLEN 81

struct namect {
	char* fname;		// Use malloc()
	char* lname;		// Use malloc()
	int letters;
};

void getinfo(struct namect*);				// allocate memory
void makeinfo(struct namect*);
void showinfo(const struct namect*);
void cleanup(struct namect*);				// free memory when done
char* s_gets(char* st, int n);

int main() {
	/* Dangerous usage */
	struct namect p = { "Bong-Hak", "Lee" };
	printf("%s %s\n", p.fname, p.lname);

	/*int f1 = scanf("%[^\n]%*c", p.lname);
	printf("%s %s\n", p.fname, p.lname);*/



	/* Recommended usage */
	char buffer[SLEN] = { 0, };
	int f2 = scanf("%[^\n]%*c", buffer);
	p.fname = (char*)malloc(strlen(buffer) + 1);
	if (p.fname != NULL) {
		strcpy(p.fname, buffer);
	}
	printf("%s %s\n", p.fname, p.lname);
	printf("\n");



	/* Problem */
	struct namect person;

	getinfo(&person);
	makeinfo(&person);
	showinfo(&person);
	cleanup(&person);


	return 0;
}

void getinfo(struct namect* un) {
	char buffer[SLEN] = { 0, };

	printf("Please enter your first name.\n");
	s_gets(buffer, SLEN);
	un->fname = (char*)malloc(strlen(buffer) + 1);
	if (un->fname != NULL) {
		strcpy(un->fname, buffer);
	}
	else {
		printf("Malloc() failed\n");
	}

	printf("Please enter your first name.\n");
	s_gets(buffer, SLEN);
	un->lname = (char*)malloc(strlen(buffer) + 1);
	if (un->lname != NULL) {
		strcpy(un->lname, buffer);
	}
	else {
		printf("Malloc() failed\n");
	}
}

void makeinfo(struct namect* un) {
	un->letters = strlen(un->fname) + strlen(un->lname);
}

void showinfo(const struct namect* un) {
	printf("Hi, %s %s. Your name has %d characters.\n",
		un->fname, un->lname, un->letters);
}

void cleanup(struct namect* un) {
	free(un->fname);
	free(un->lname);
}

char* s_gets(char* st, int n) {
	char* ret_val;
	char* find;

	ret_val = fgets(st, n, stdin);
	if (ret_val) {
		find = strchr(ret_val, '\n');
		if (find) {
			*find = '\0';
		}
		else {
			while (getchar() != '\n') {
				continue;
			}
		}
	}

	return ret_val;
}