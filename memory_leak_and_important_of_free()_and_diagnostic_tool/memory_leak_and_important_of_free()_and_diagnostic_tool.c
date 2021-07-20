#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>		// malloc(), free()

int main() {
	// memory leak : 메모리를 반납하지 않았을 경우 생기는 메모리 누수
	// 진단도구 Diagnostic Tool을 이용해 memory leak 확인 가능
	printf("Dummy Output\n");

	{
		int n = 100000000;
		int* ptr = (int*)malloc(n * sizeof(int));
		
		if (!ptr) {
		//if (ptr == NULL) {
			printf("Malloc() failed\n");
			exit(EXIT_FAILURE);
		}

		for (int i = 0; i < n; ++i) {
			ptr[i] = i + 1;
		}

		free(ptr);
		//ptr = NULL;
	}
	/* 
		what happens if there is not free()? 
		- ptr은 사라졌지만 메모리 공간은 유지되고 있고,
		식별자를 잃어 버렸기 때문에 해당 메모리 공간에 
		추가적인 작업을 할 수 없다.
		- 또한, 메모리 누수가 일어나기 때문에 메모리 
		누수가 지속되면, 컴퓨터에 문제가 발생한다.
	*/


	// 식별자를 잃어 버려도 해당 메모리 공간에 접촉하는 방법 - 주소 옮겨 적어 놓기
	int* ptr_backup = NULL;

	{
		int n = 100000000;
		int* ptr = (int*)malloc(n * sizeof(int));

		if (!ptr) {
			//if (ptr == NULL) {
			printf("Malloc() failed\n");
			exit(EXIT_FAILURE);
		}

		for (int i = 0; i < n; ++i) {
			ptr[i] = i + 1;
		}

		printf("%d %d\n", ptr[0], ptr[1]);

		ptr_backup = ptr;

		//free(ptr);	// 이 경우 반납을하면 백업한 의미가 없어짐 -> run-time error
	}
	printf("%d %d\n", ptr_backup[0], ptr_backup[1]);
	free(ptr_backup);
	ptr_backup = NULL;

	printf("Dummy Output\n");

	return 0;
}