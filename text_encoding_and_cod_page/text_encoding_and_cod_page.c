#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>		// exit()
#include <Windows.h>	// SetConsoleOutputCP() - 인코딩 방식과 관련됨

int main() {
	const UINT default_cp = GetConsoleOutputCP();
	printf("%u\n", default_cp);		// 현재 인코딩에 사용하는 방식을 알 수 있음 -> 기본 모드

	int ch;
	FILE* fr, * fw;

	const char* in_filename = "원본.txt";
	//const char* in_filename = "원본_ansi.txt";
	
	const char* out_filename = "사본.txt";
	//const char* out_filename = "사본_ansi.txt";


	unsigned long count = 0;

	if ((fr = fopen(in_filename, "r")) == NULL) {	// Open a text file for reading
		printf("Can't open %s\n", in_filename);
		exit(EXIT_FAILURE);
	}

	if ((fw = fopen(out_filename, "w")) == NULL) {	// Open a text file for writing
		printf("Can't open %s\n", out_filename);
		exit(EXIT_FAILURE);
	}
	
	SetConsoleOutputCP(CP_UTF8);		// UTF-8 mode

	while ((ch = fgetc(fr)) != EOF) {
		fputc(ch, stdout);
		fputc(ch, fw);

		count++;
	}
	printf("\n\n");

	fclose(fr);		
	fclose(fw);

	SetConsoleOutputCP(default_cp);		// ISO 2022 Korean -> 기본 모드로 돌아가기

	printf("FILE %s has %lu characters\n", in_filename, count);
	printf("Copied to %s\n", out_filename);

	printf("한글 출력 확인\n");

	return 0;
}