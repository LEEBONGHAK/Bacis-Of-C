#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>		// malloc(), free()

int main() {
	/* Not Dynamic Storage Allocations */
	float x;
	char str[] = "Dancing with a Star";

	int arr[100];


	/* Dynamic Storage Allocations */
	/*
		malloc() returns a void type pointer.
		void* : generic pointer -> 특변한 자료형을 가진게 아닌 순수한 포인터

		free() deallocates the memory
	*/
	double* ptr = NULL;

	ptr = (double*)malloc(30 * sizeof(double));		// 할당을 원하는 크기의 메모리의 첫번째 주소를 반환 즉, 배열과 비슷

	if (ptr == NULL) {
		puts("Memory allocation failed");

		/*
			exit()을 사용하면 어떤 함수에서도 강제 종료 가능
			exit(EXIT_FAILURE) is similar to return 1 IN main()
			exit(EXIT_SUCCESS) is similar to return 0 IN main()
		*/

		exit(EXIT_FAILURE);
	}

	printf("Before free %p\n", ptr);

	free(ptr);		// no action occurs when ptr is NULL
	printf("After free %p\n", ptr);		// 포인터는 별도의 변수이기 때문에 free()를 해주어도 주소를 계속 가지고 있음

	ptr = NULL;		// optional - 여러가지로 안전기에 권장됨 (포인터가 가지고 있은 주소를 초기화 가능)
	printf("\n");


	/* Dynamically Allocated Array */
	int n = 5;
	ptr = (double*)malloc(n * sizeof(double));		// 초기화를 해주진 않음

	if (ptr != NULL) {
	//if (!ptr) {
		for (int i = 0; i < n; ++i) {
			printf("%f\n", ptr[i]);
		}
		printf("\n");

		for (int i = 0; i < n; ++i) {
			*(ptr + i) = (double)i;					// 배열처럼 사용 가능
		}

		for (int i = 0; i < n; ++i) {
			printf("%f ", ptr[i]);
		}
		printf("\n");
	}

	free(ptr);
	ptr = NULL;

	/*
		Comparision to VLA

		VLA
		- no supported by VS compilers.
		- automatic duration, cannot be resized
		- limited by stack size (when compiler places VLA in stack segment)
	*/

	return 0;
}