#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>		// exit()

int main(int argc, char* argv[]) {
	int ch;		// buffer로 부터 읽을 수 있도록
	FILE* fr;	// file을 처리할 때 필요한 data의 묶음(structure)에 대한 포인터 - file pointer to read
	FILE* fw;	// file pointer to write

	/*
	typedef struct _iobuf
	{
		char* _ptr;
		int _cnt;
		char* _base;
		int _flag;
		int _file;
		int _charbuf;
		int _bufsiz;
		char* _tmpfname;
	} FILE;
	*/

	const char* out_filename = "output.txt";	// for writing

	unsigned long count = 0;

	if (argc != 2) {
		printf("Usage: %s filename\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	if ((fr = fopen(argv[1], "r")) == NULL) {	// Open a text file for reading
		printf("Can't open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	if ((fw = fopen(out_filename, "w")) == NULL) {	// Open a text file for writing
		printf("Can't open %s\n", out_filename);
		exit(EXIT_FAILURE);
	}
	/*
		fopen mode strings for text files
		- r : reading
		- w : creating-and-writing or over-writing
		- a : appending(덧붙임) or creating-and-writing
		- r+ : both reading and writing
		- w+ : reading and writing, over-writing or creating
		- a+ : reading and writing, appending or creating
	*/

	
	while ((ch = fgetc(fr)) != EOF) {		//getc(fr)
		//putc(ch, stdout);		// same as putchar(ch);
		fputc(ch, stdout);		// same as putchar(ch);
		fputc(ch, fw);			// fw stream에 ch를 출력 -> out_filename에 출력

		count++;
	}
	printf("\n\n");

	fclose(fr);		// 처리가 되지 않은 buffer를 처리해줌
	fclose(fw);

	printf("FILE %s has %lu characters\n", argv[1], count);
	printf("Copied to %s\n", out_filename);

	return 0;
}