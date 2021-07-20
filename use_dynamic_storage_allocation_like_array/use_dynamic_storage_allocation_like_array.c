#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>		// malloc(), free()

int main() {
	/* One variable */
	// 변수 하나에 대한 포인터처럼 사용 가능
	int* ptr = NULL;
	
	ptr = (int*)malloc(sizeof(int) * 1);
	if (!ptr)
		exit(1);

	*ptr = 1024 * 3;
	printf("%d\n", *ptr);

	free(ptr);
	ptr = NULL;
	printf("\n");


	/* 1-D array */
	// 1차원 배열처럼 사용하는 경우 - 차이점: stack(배열), heap(동적할당)
	int n = 3;

	ptr = (int*)malloc(sizeof(int) * n);
	if (!ptr)
		exit(1);

	ptr[0] = 123;
	*(ptr + 1) = 456;
	*(ptr + 2) = 789;

	free(ptr);
	ptr = NULL;


	/* 2-D array */
	int row = 3, col = 2;

	int(*ptr2d)[2] = (int(*)[2])malloc(sizeof(int) * row * col);			// 동적 할당의 의미가 퇴색됨
	//int(*ptr2d)[col] = (int(*)[col])malloc(sizeof(int) * row * col);		// VLA
	if (!ptr2d)
		exit(1);

	for (int r = 0; r < row; r++) {
		for (int c = 0; c < col; c++) {
			ptr2d[r][c] = c + col * r;
		}
	}

	for (int r = 0; r < row; r++) {
		for (int c = 0; c < col; c++) {
			printf("%d ", ptr2d[r][c]);
		}
		printf("\n");
	}

	free(ptr2d);
	ptr2d = NULL;
	printf("\n");


	/* 
		Using 1D arrays as 2D arrays
		
		row = 3, col = 2

		(r, c)

		2D
		(0, 0) (0, 1)
		(1, 0) (1, 1)
		(2, 0) (2, 1)

		1D
		(0, 0) (0, 1) (1, 0) (1, 1) (2, 0) (2, 1)
		0	   1      2      3      4      5      = c + col * r
	*/
	int row1 = 3, col1 = 2;

	ptr = (int*)malloc(row * col * sizeof(int));
	if (!ptr)
		exit(1);

	for (int r = 0; r < row; r++) {
		for (int c = 0; c < col; c++) {
			ptr[c + col * r] = c + col * r;
		}
	}

	for (int r = 0; r < row; r++) {
		for (int c = 0; c < col; c++) {
			printf("%d ", *(ptr + c + col * r));
		}
		printf("\n");
	}

	free(ptr);
	ptr = NULL;
	printf("\n\n");


	/*
		Using 1D arrays as 3D arrays

		row = 3, col = 2, depth = 2

		(r, c, d)

		3D
		-------------------
		(0, 0, 0) (0, 1, 0)
		(1, 0, 0) (1, 1, 0)
		(2, 0, 0) (2, 1, 0)
		-------------------
		(0, 0, 1) (0, 1, 1)
		(1, 0, 1) (1, 1, 1)
		(2, 0, 1) (2, 1, 1)
		-------------------

		1D
		(0, 0, 0) (0, 1, 0) (0, 0, 0) (0, 1, 0) (0, 0, 0) (0, 1, 0) (0, 0, 0) (0, 1, 0) (0, 0, 0) (0, 1, 0) (0, 0, 0) (0, 1, 0)
		0         1		    2		  3			4		  5			6		  7			8		  9			10		  11
		= c + col * r + (col * row) * d


		if 4D
		row, col, depth, height
		(r, c, d, h)
		index = c + col * r + (col * row) * d + (col * row * depth) * h
	*/
	int row2 = 3, col2 = 2, depth = 2;

	ptr = (int*)malloc(row * col * depth * sizeof(int));
	if (!ptr)
		exit(1);

	for (int d = 0; d < depth; d++) {
		for (int r = 0; r < row; r++) {
			for (int c = 0; c < col; c++) {
				ptr[c + col * r + (col * row) * d] = c + col * r + (col * row) * d;
			}
		}
	}

	for (int d = 0; d < depth; d++) {
		for (int r = 0; r < row; r++) {
			for (int c = 0; c < col; c++) {
				printf("%d ", *(ptr + c + col * r + (col * row) * d));
			}
			printf("\n");
		}
		printf("\n");
	}

	/*
		index 편한게 사용하는 방법 -> 함수
		
		int idx2(int c, int r) {
			return c + col * r
		}

		int idx3(int c, int r, int d) {
			static const int cr = col * row;
			return c + col * r + cr * d;
		}
	*/

	free(ptr);
	ptr = NULL;
	printf("\n");


	return 0;
}