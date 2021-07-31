#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	/*
		Program written in C

		Translating		- 번역
		Preprocessing	- 전처리
		Compiling		- 컴파일
		Linking			- 링킹

		Executable
	*/

	/* International characters */
	puts("안녕하세요? 한글을 사랑합니다.\n");



	/*
		Trigraph Sequences
		- Some keyboards don't provide all the symbols used in C.
		- Three-character sequences

		Trigraph		Replacement
		??=				#
		??/				\
		??'				^
		??(				[
		??)				]
		??!				|
		??<				{
		??>				}
		??-				~

		/Zc:trigraphs
		=> trigraph 사용법이 안될경우 project properties-command line-additional options에 써주어야 함
	*/
	int arr[3] = { 1,2,3 };
	printf("Trigraph: ");
	printf("arr??(0??) == %d\n\n", arr??(0??));		// 최근에는 trigraph 사용법이 흔하지 않기 때문에 IDE에서 표시해 줌(호환성 문제)
	//printf("arr[0] == %d\n", arr[0]);



	/*
		Digraphs
		- Two-character sequences

		Digraph			Equivalent
		<:				[
		:>				]
		<%				{
		%>				}
		%:				#
	*/
	printf("Digraph: ");
	printf("arr<:1:> == %d\n\n", arr<:1:>);
	//printf("arr[1] == %d\n", arr[1]);
	
	

	/* Two physical lines vs One logical line */
	printf("This is a very very very very very very very very very very very very long long line\n");
	printf("This is a very very very very very \
very very very very very very very long long line\n\n");



	/*
		Tokens
		- Groups separated from each other by spaces, tabs, or line breaks
		Whitespace cahracters -> a single space
	*/
	int/*a variable to count a number*/n = 1;
	//int n = 1;

	
	return 0;
}