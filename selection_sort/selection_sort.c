#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

/*
	Selection Sort Algorithm
	https://www.geeksforgeeks.org/selection-sort/

	Youtube search "Selection Sort", "C550"

	64 25 12 22 11 (min_idx = 0)
	   64		   (min_idx = 0)
	   25		   (min_idx = 1)
		  25       (min_idx = 1)
		  12 	   (min_idx = 2)
			 12    (min_idx = 2)
				12 (min_idx = 2)
				11 (min_idx = 4)
	11 25 12 22 64 (swap arr[0] and arr[4])

	11 25 12 22 64 (min_idx = 1)
		  25       (min_idx = 1)
		  12 	   (min_idx = 2)
			 12    (min_idx = 2)
				12 (min_idx = 2)
	11 12 25 22 64 (swap arr[1] and arr[2])

	11 12 25 22 64 (min_idx = 2)
	...
*/

void swap(int* xp, int* yp);
void printArray(int arr[], int size);
void selectionSort(int arr[], int n);

int main() {
	int arr[5] = { 64,25,12,22,11 };
	//int arr[6] = { 5,2,6,3,1,4 };
	int n = sizeof(arr) / sizeof(arr[0]);

	printArray(arr, n);
	selectionSort(arr, n);		// ascending order
	printArray(arr, n);

	return 0;
}

void swap(int* xp, int* yp) {
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void printArray(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void selectionSort(int arr[], int n) {
	int min_idx;

	// One by one move boundary of unsorted subarray
	for (int i = 0; i < n - 1; i++) {	// Note n - 1
		min_idx = i;
										// Find the minimum element is unsorted array
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[min_idx]) {
				min_idx = j;
			}
		}
		// Swap the found minimum element with the first element
		swap(&arr[i], &arr[min_idx]);
	}
}
