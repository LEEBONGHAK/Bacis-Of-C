#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	// 2차원 배열도 메모리는 1차원
	int arr[2][3] = { {1,2,3},
					  {4,5,6} };

	//int arr[2][3] = { 1,2,3,		// 이것도 가능, 알아서 나누어 줌
	//				    4,5,6 };	
	//int arr[2][3] = { 1,2 };		// insufficient initializer

	printf("%d\n\n", arr[1][1]);

	for (int j = 0; j < 2; ++j) {
		for (int i = 0; i < 3; ++i) {
			printf("%d ", arr[j][i]);
		}
		printf("\n");
	}
	printf("\n");

	// Note: inner loop uses i. Why?
	// 데이터를 더 빠르게 가져오기 위해서
	// 원소를 읽어오는 순서와 데이터가 메모리가 저장되어 있는 순서가 같으면 더 빨리 읽음


	int* ptr = &arr[0][0];	// 포인터를 이용해 1차원 배열인 것처럼 사용하기
	for (int k = 0; k < 6; ++k) {
		printf("%d ", ptr[k]);
	}
	printf("\n\n");

	printf("%zd %zd\n", sizeof(arr), sizeof(arr[0]));
	printf("\n\n");
	

	/* 3D array - 응용과목(딥러닝, vision 등)에 많이 사용됨 */
	int arr_3d[2][3][4] = {
							{
								{000,001,002,003},
								{010,011,012,013},
								{020,021,022,023},
													}, 	
							{
								{100,101,102,103},
								{110,111,112,113},
								{120,121,122,123},
													}
														};

	for (int k = 0; k < 2; ++k) {
		for (int j = 0; k < 3; ++j) {
			for (int i = 0; i < 4; ++i) {
				printf("%d ", arr_3d[k][j][i]);
			}
			printf("\n");
		}
		printf("\n");
	}
	printf("\n");


	return 0;
}