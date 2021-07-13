#define _CRT_SECURE_NO_WARNINGS		// Visual Studio가 아니면 필요 없음

#include <stdio.h>

#define ROWS 3
#define COLS 4

int sum2d_4(int row, int col, int* ar);

int main() {
	/*
		Visual Studio에서는 variable-length arrays(VLAs) 
		즉, 변수로 길이를 정할 수 있는 배열은 컴파일이 안됨
		- 동적 할당 메모리을 많이 사용하기 때문에 VLAs는 많이 쓰이진 않음

		따라서, VLAs가 가능한 다른 컴파일러를 사용해야 하며,
		아래코드는 참고용으로 작성한 것임
	*/

	int n;

	printf("Input array length : ");
	scanf("%d", &n);

	//int n = 7;
	float my_arr[n];	// Note: cannot change length after declaration


	for (int i = 0; i < n; ++i) {
		my_arr[i] = (float)i;
	}

	for (int i = 0; i < n; ++i) {
		printf("%f\n", my_arr[i]);
	}


	int data[ROWS][COLS] = {
		{1,2,3,4},
		{5,6,7,8},
		{9,0,1,2}
	};

	printf("%d\n", sum2d_4(ROWS, COLS, data));

	return 0;
}

int sum2d_4(int row, int col, int* ar) {
	int r, c, tot = 0;
	for (r = 0; r < row; r++) {
		for (c = 0; c < col; c++) {
			tot += *(ar + c + col * r);		// ar[c + col * r]
		}
	}

	return tot;
}