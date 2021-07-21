#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>		// exit()

/*
	ABCDEF ...
	Current position 0 and read -> A
	Current position 1 and read -> B
	...
*/

int main() {
	int ch;
	long cur;

	FILE* fp = fopen("test.txt", "r");

	cur = ftell(fp);			// ftell(): 현재 위치를 알려줌 (시작점에서 몇 byte만큼 떨어져 있는지)
	printf("ftell() = %ld\n", cur);

	/* SEEK_SET */
	fseek(fp, 2L, SEEK_SET);	// fseek(): 위치 이동, SEEK_CUR: 처음 위치에서 해당하는 만큼 이동

	cur = ftell(fp);
	printf("ftell() = %ld\n", cur);		// 67 C
	
	ch = fgetc(fp);				// 해당 위치의 문자 읽기
	printf("%d %c\n", ch, ch);

	cur = ftell(fp);			// 읽었기 때문에 1 byte 이동
	printf("ftell() = %ld\n", cur);


	/* SEEK_CUR */
	fseek(fp, -2L, SEEK_CUR);	// SEEK_CUR: 현재 위치에서 해당하는 만큼 이동

	cur = ftell(fp);
	printf("ftell() = %ld\n", cur);

	ch = fgetc(fp);
	printf("%d %c\n", ch, ch);	// 66 B



	/* SEEK_END */
	fseek(fp, 0L, SEEK_END);	// SEEK_END: 끝에서 부터 해당하는 만큼 이동
	ch = fgetc(fp);
	printf("%d %c\n", ch, ch);	// -1 (= EOF)

	fseek(fp, -1L, SEEK_END);
	ch = fgetc(fp);
	printf("%d %c\n", ch, ch);	// 90 Z

	fseek(fp, -2L, SEEK_END);
	ch = fgetc(fp);
	printf("%d %c\n", ch, ch);	// 89 Y
	printf("\n");


	/* fsetpos(), fgetpos() -> 파일이 많이 큰 경우 사용 */
	fpos_t pt;
	pt = 10;

	fsetpos(fp, &pt);				// return 0 ok (fseek() 과 비슷)
	
	ch = fgetc(fp);
	printf("%d %c\n", ch, ch);		// 75 K

	fgetpos(fp, &pt);				// return 0 ok (ftell() 과 비슷)
	printf("%lld\n", pt);			// NOTE: not meant to be read directly
	printf("\n");



	/* binary file random access */
	// make a test binary file
	{
		FILE* fp1 = fopen("binary", "wb");
		for (int i = 0; i < 100; ++i) {
			double d = i * 1.11;
			fwrite(&d, sizeof(double), 1, fp1);
		}
		fclose(fp1);
	}

	// read
	FILE* fp1 = fopen("binary", "rb");
	long cur1;
	double d;

	cur1 = ftell(fp1);
	printf("Before reading %ld\n", cur1);	// 현재 위치

	fread(&d, sizeof(double), 1, fp1);		// double -> 8 byte in x86

	cur1 = ftell(fp1);
	printf("After reading %ld\n", cur1);
	
	printf("%f\n", d);

	fread(&d, sizeof(double), 1, fp1);

	printf("%f\n", d);

	cur1 = ftell(fp1);
	printf("After reading %ld\n", cur1);

	fseek(fp1, 32L, SEEK_SET);	// 32 = 4 * 8
	fread(&d, sizeof(double), 1, fp1);
	printf("%f\n", d);
	printf("\n");

	return 0;
}