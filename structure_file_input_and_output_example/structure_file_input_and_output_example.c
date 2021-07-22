#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>		// calloc(), free(), exit()
#include <conio.h>

#define SLEN 101

struct book {
	char name[SLEN];
	char author[SLEN];
};

void print_books(const struct book* books, int n);
void write_books(const char* filename, const struct book* books, int n);
struct book* read_books(const char* filename, int* n);
void read_books2(const char* filename, struct book** books_dptr, int* n);

int main() {
	int temp;
	int n = 3;
	const char* filename = "books.txt";

	struct book* my_books = (struct book*)malloc(sizeof(struct book) * 3);

	if (!my_books) {
		printf("Malloc failed\n");
		exit(1);
	}

	my_books[0] = (struct book){ "The Great Gatsby", "F. Scott fitzgerald" };
	my_books[1] = (struct book){ "Hamlet", "William Shakespeare" };
	my_books[2] = (struct book){ "The Odyssey", "Homer" };

	print_books(my_books, 3);

	printf("\nWriting to a file.\n");
	write_books(filename, my_books, n);
	free(my_books);
	n = 0;
	printf("Done.\n");

	printf("\nPress any key to read data from a file.\n\n");
	temp = _getch();

	my_books = read_books(filename, &n);
	//read_books2(filename, &my_books, &n);
	print_books(my_books, n);
	free(my_books);
	n = 0;

	return 0;
}

void print_books(const struct book* books, int n) {
	for (int i = 0; i < n; ++i) {
		printf("Book %d : \"%s\" written by \"%s\"\n", i + 1, books[i].name, books[i].author);
	}
}

void write_books(const char* filename, const struct book* books, int n) {
	FILE* file = fopen(filename, "w");

	if (file == NULL) {		// Open a text file for writing
		fputs("Can't open file.\n", stderr);
		exit(1);
	}

	fprintf(file, "%d\n", n);		// number of books

	for (int i = 0; i < n; ++i) {
		fprintf(file, "%s\n%s\n", books[i].name, books[i].author);
	}

	fclose(file);
}

struct book* read_books(const char* filename, int* n) {
	FILE* file = fopen(filename, "r");

	if (file == NULL) {		// Open a text file for writing
		fputs("Can't open file.\n", stderr);
		exit(1);
	}

	int flag;
	
	// 몇 개인지?
	flag = fscanf(file, "%d%*c", n);		// Remove last '\n'

	if (flag != 1) {
		printf("File read failed\n");
		exit(1);
	}

	struct book* books = (struct book*)calloc(*n, sizeof(struct book));		// calloc()
	if (!books) {
		printf("Malloc() failed.");
		exit(1);
	}

	for (int i = 0; i < *n; ++i) {
		flag = fscanf(file, "%[^\n]%*c%[^\n]%*c", books[i].name, books[i].author);
		
		if (flag != 2) {
			printf("File read failed\n");
			exit(1);
		}
	}

	fclose(file);

	return books;
}

void read_books2(const char* filename, struct book** books_dptr, int* n) {
	FILE* file = fopen(filename, "r");

	if (file == NULL) {		// Open a text file for writing
		fputs("Can't open file.\n", stderr);
		exit(1);
	}

	int flag;

	// 몇 개인지?
	flag = fscanf(file, "%d%*c", n);		// Remove last '\n'
	if (flag != 1) {
		printf("File read failed\n");
		exit(1);
	}

	struct book* books = (struct book*)calloc(sizeof(struct book), *n);		// calloc()
	if (!books) {
		printf("Malloc() failed.");
		exit(1);
	}

	for (int i = 0; i < *n; ++i) {
		flag = fscanf(file, "%[^\n]%*c%[^\n]%*c", books[i].name, books[i].author);

		if (flag != 2) {
			printf("File read failed\n");
			exit(1);
		}
	}

	fclose(file);

	*books_dptr = books;
}