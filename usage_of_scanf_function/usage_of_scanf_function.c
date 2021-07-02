#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <inttypes.h> // intmax_t

int main() {
	/* multiple inputs with blank separators */
	int i;
	float f;
	char str[30];
	scanf("%d %f %s", &i, &f, str); // Note & is absent in front of str


	/* character */
	char c;
	scanf("Try to input blank: %c", &c); // try blank
	printf("%i\n", c); // blank is 32


	/* Unsigned as signed */
	unsigned i1;
	scanf("try negative number: %i", &i1);
	printf("%i\n", i1); 
	// unsigned인데 받을 때 signed로 받고 unsigned로 저장 후 signed로 출력하기 때문에 오류가 나타나지 않음


	/* Unsigned as unsigned */
	unsigned i2;
	scanf("try negative number: %u", &i2);
	printf("%i\n", i2);
	// unsigned인데 받을 때 unsigned로 받고 unsigned로 출력하기 때문에 숫자가 깨짐(형식 지정자 보기)


	/* Floating point numbers */
	// l for double for % f, % e, % E, % ㅎ
	double d = 0.0;
	scanf("%lf", &d);	// lf, try E notation
	printf("%f\n", d);	// f


	/* Width */
	char str0[30];
	scanf("%5s", str0);	// width : 몇 글자까지만 입력을 받을 것인지
	printf("%s\n", str0);


	/* h modifier */
	char i3;
	scanf("try large numbers: %hhd", &i3);
	printf("%i\n", i3);


	/* integer with characters */
	int i4;
	scanf("try '123ab' or '123a456': %i", &i4); // 문자가 만나면 문자를 만나기전 숫자까지만 입력받음	
	printf("%i\n", i4); 


	/* j modifier */
	intmax_t i5; // 가장 큰 정수형 타입
	scanf("%ji", &i5);
	printf("%ji\n", i5);


	/* Regular characters - 정규식에 관련된 내용 */
	int a, b;
	// 각 알맞는 구분자를 사용해야함
	scanf("%d %d", &a, &b);
	printf("%d %d\n", a, b);
	
	scanf("%d,%d", &a, &b);
	printf("%d %d\n", a, b);

	scanf("%d ,%d", &a, &b);
	printf("%d %d\n", a, b);
	
	scanf("%d, %d", &a, &b);
	printf("%d %d\n", a, b);
	
	scanf("%d-%d", &a, &b);
	printf("%d %d\n", a, b);
	
	scanf("%dA%d", &a, &b);
	printf("%d %d\n", a, b);


	/* char receives blank */
	int a1, b1;
	char c1;
	scanf("try 123 456 (blank): %d%c%d", &a1, &c1, &b1);
	printf("%d|%c|%d\n", a1, c, b1); // | is seperator

	// sentences?, getchar(), fgets(), etc. -> 입출력을 하는 다른 다양한 함수들

	/* return value of scanf() */
	int a2, b2;
	int i6 = scanf("%d%d", &a2, &b2);
	printf("%d", i6); // 입력을 몇개나 받았는가?


	/* * modifier for printf() */
	int i7 = 1;
	int width = 5; // from script file, scanf, etc.
	printf("Input width : ");
	scanf("%d", &width);
	printf("%*d\n", width, i7);


	/* * modifier for scanf() */
	int i8 = 1;
	scanf("%*d%*d%d", i8); // 입력은 다 받지만 *가 있으면 무시됨
	printf("Your third input %d\n", i8);


	return 0;
}