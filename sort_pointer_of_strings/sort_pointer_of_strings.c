#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>		//strcmp

void swap(char** xp, char** yp);		//Note: Optional
void printStringArray(char* arr[], int size);
void selectionSort(char* arr[], int n);

int main() {
	char* arr[] = { "Cherry", "AppleBee", "Pineapple", "Apple", "Orange" };
	int n = sizeof(arr) / sizeof(arr[0]);

	printStringArray(arr, n);
	selectionSort(arr, n);
	printStringArray(arr, n);

	return 0;
}

void swap(char** xp, char** yp) {
	char* temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void printStringArray(char* arr[], int size) {
	for (int i = 0; i < size; i++) {
		printf("%s ", arr[i]);
	}
	printf("\n");
}

void selectionSort(char* arr[], int n) {
	int min_idx;

	// One by one move boundary of unsorted subarray
	for (int i = 0; i < n - 1; i++) {
		min_idx = i;

		// Find the minimum element in unsorted array
		for (int j = i + 1; j < n; j++) {
			if (strcmp(arr[j], arr[i]) <0) {
				min_idx = j;
			}
		}

		// Swap the found minimum element with the first element
		swap(&arr[i], &arr[min_idx]);
	}
}