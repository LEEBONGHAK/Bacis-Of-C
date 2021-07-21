#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	FILE* fp;
	int ch;

	/* ungetc() - 한 글자를 읽은 후 buffer에 그 글자를 다시 넣음 */
	fp = fopen("input.txt", "r");

	ch = fgetc(fp);			// 한 글자 읽고
	fputc(ch, stdout);		// 출력 "

	ungetc(ch, fp);			// try another characters

	ch = fgetc(fp);
	fputc(ch, stdout);		// "

	ch = fgetc(fp);
	fputc(ch, stdout);		// I

	fclose(fp);
	printf("\n\n");



	/* setvbuf() - buffer의 설정을 바꿀 수 있음 */
	fp = fopen("input.txt", "r");

	char buffer[32] = { '\0', };

	// buffer를 만듬
	setvbuf(fp, buffer, _IOFBF, sizeof(buffer));		// _IOLBF(line / 한줄씩), _IOFBF(full / 통째로), _IONBF(no / 사용하지 않음)

	// buffer status before read
	for (int i = 0; i < sizeof(buffer); ++i) {
		printf("%hhd", buffer[i]);
	}
	printf("\n");

	ch = fgetc(fp);		// Read just only a single character!

	// dump buffer
	for (int i = 0; i < sizeof(buffer); ++i) {
		printf("%c", buffer[i]);
	}
	printf("\n\n");

	fclose(fp);
	/*
		buffer라는 것은 프로그램이 이 파일의 내용을 계속 읽을 것으로 
		예상되면, 미리 파일의 내용을 buffer에 올려둠.

		buffer에서 가져오면 비교적 빠름
	*/



	/* fflush() - buffer에 쌓여있는 data를 내려보내라 (반드시 다 출력) */
	
	// Writing a large amount of data
	// fflush(fp);


	return 0;
}