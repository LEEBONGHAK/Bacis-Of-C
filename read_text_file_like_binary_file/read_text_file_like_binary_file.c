#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <Windows.h>	// SetConsoleOutputCP()

int main() {
	FILE* fp = fopen("test.txt", "rb");

	unsigned char ch;

	SetConsoleOutputCP(CP_UTF8);		/// UTP-8 mode

	while (fread(&ch, sizeof(unsigned char), 1, fp) > 0) {
		printf("%c", ch);
	}
	printf("\n\n");

	rewind(fp);
	//fp = fopen("test.txt", "rb");

	while (fread(&ch, sizeof(unsigned char), 1, fp) > 0) {
		printf("%hhu %c\n", ch, ch);		// 알파벳를 제외한 다른 언어를 사용할 때는 더 많은 byte를 사용할 수도 있고, 이러한 고려가 필요
	}
	printf("\n");

	fclose(fp);

	return 0;
}