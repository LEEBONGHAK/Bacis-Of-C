#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>		// exit()

int main() {
	int c;
	FILE *file = NULL;		// 포인터 변수이며, 주소를 저장
	char file_name[] = "my_file.txt";

	file = fopen(file_name, "r");		// read or write
	if (file == NULL) {
		printf("Failed to open file.\n");
		exit(1);
	}
	
	while ((c = getc(file)) != EOF) {	// file의 문자를 EOF를 만나기 전까지 출력
		putchar(c);
	}
	fclose(file);		// 파일 닫기
	printf("\n");

	return 0;
}