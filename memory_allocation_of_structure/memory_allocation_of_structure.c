#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main() {
	/* Well aligned structure */
	struct Aligned {
		int a;
		float b;
		double c;
	};

	/*
		|0 1 2 3 4 5 6 7|8 9 10 11 12 13 14 15|
		|int a  |float b|double c			  |

		4 + 4 + 8 = 16
	*/

	struct Aligned a1, a2;

	printf("struct Aligned a1\n");
	printf("Sizeof %zd\n", sizeof(struct Aligned));
	printf("%lld\n", (long long)&a1);
	printf("%lld\n", (long long)&a1.a);
	printf("%lld\n", (long long)&a1.b);
	printf("%lld\n", (long long)&a1.c);

	printf("\nstruct Aligned a2\n");
	printf("Sizeof %zd\n", sizeof(a2));
	printf("%lld\n", (long long)&a2);
	printf("%lld\n", (long long)&a2.a);
	printf("%lld\n", (long long)&a2.b);
	printf("%lld\n", (long long)&a2.c);



	/*
		padding (struct member alignment(줄 맞춤))
		- 데이터를 주고 받을 때 1 word만큼 묶어서 보냄
		- 1 word: 4 byte in x86, 8 byte in x64
	*/
	struct Padded1 {
		char a;
		float b;
		double c;
	};

	/*
		Without padding

		|0 1 2 3 4 5 6 7|8 9 10 11 12 13 14 15|16
		|a|float b|double c			 | ?  ?  ?|   -> 1 word씩 보내면 double c가 짤려서 보내짐 (불편난감)

		1 + 4 + 8 = 13
	*/
	/*
		With padding

		|0 1 2 3 4 5 6 7|8 9 10 11 12 13 14 15|16 
		|char a |float b|double c			  |   -> 1 word를 맞춰주기 위해 padding 사용

		4 + 4 + 8 = 16
	*/

	struct Padded1 p1;

	printf("\nstruct Padded1 p1\n");
	printf("Sizeof %zd\n", sizeof(p1));		// 4 + 4 + 8 = 16
	printf("%lld\n", (long long)&p1);
	printf("%lld\n", (long long)&p1.a);
	printf("%lld\n", (long long)&p1.b);
	printf("%lld\n", (long long)&p1.c);


	struct Padded2 {
		float b;
		double c;
		char a;
	};

	/*
		|0 1 2 3 4 5 6 7|8 9 10 11 12 13 14 15|16 17 18 19 20 21 22 23|24
		|float b        |double c			  |char a				  |

		8 + 8 + 8 = 24
		-> 효율을 위한다면 구조체를 선언할 때 자료형의 순서 고려도 필요
	*/

	struct Padded2 p2;
	
	printf("\nstruct Padded2 p2\n");
	printf("Sizeof %zd\n", sizeof(p2));		// 8 + 8 + 8 = 24 
	printf("%lld\n", (long long)&p2);
	printf("%lld\n", (long long)&p2.a);
	printf("%lld\n", (long long)&p2.b);
	printf("%lld\n", (long long)&p2.c);


	struct Padded3 {
		char a;
		double b;
		double c;
	};

	/*
		|0 1 2 3 4 5 6 7|8 9 10 11 12 13 14 15|16 17 18 19 20 21 22 23|24
		|char a         |double b			  |double c				  |

		8 + 8 + 8 = 24
	*/

	struct Padded1 p3;

	printf("\nstruct Padded3 p3\n");
	printf("Sizeof %zd\n", sizeof(p3));		// 8 + 8 + 8 = 24
	printf("%lld\n", (long long)&p3);
	printf("%lld\n", (long long)&p3.a);
	printf("%lld\n", (long long)&p3.b);
	printf("%lld\n", (long long)&p3.c);


	struct Person {
		char name[41];		// member
		int age;			// member
		float height;		// member
	};

	struct Person memory;

	printf("\nstruct Person memeory\n");
	printf("Sizeof %zd\n", sizeof(memory));		// 40 + 4 + 4 + 4 = 52  - 이 경우 padding rule 고려해야함
	printf("%lld\n", (long long)&memory);
	printf("%lld\n", (long long)&memory.name[0]);
	printf("%lld\n", (long long)&memory.age);
	printf("%lld\n", (long long)&memory.height);



	struct Person f[4];

	printf("\nSizeof a Person structure array %zd\n", sizeof(f));		// 208
	/*
		|f[0].name        |f[0].age	|f[0].height | ... ... |f[0].name        |f[0].age	|f[0].height |
	*/

	// padding은 compiler가 결정하는 것!!

	return 0;
}