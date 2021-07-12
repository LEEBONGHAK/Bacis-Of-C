#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MONTH 12
#define YEARS 3

int main() {
	double year2016[MONTH] = { -3.2,0.2,7.0,14.1,19.6,23.6,26.2,28.0,23.1,16.1,6.8,1.2 };
	double year2017[MONTH] = { -1.8,-0.2,6.3,13.9,19.5,23.3,26.9,25.9,22.1,16.4,5.6,-1.9 };
	double year2018[MONTH] = { -4.0,-1.6,8.1,13.0,18.2,23.1,27.8,28.8,21.5,13.1,7.8,-0.6 };

	/*
		1. Use 2D array
		2. Print data
		3. Calculate and print yearly average temperatures of 3 years
		4. Calculate and print monthly average temperatures of 3 years
	*/

	double temperature[YEARS][MONTH] = {
											{ -3.2,0.2,7.0,14.1,19.6,23.6,26.2,28.0,23.1,16.1,6.8,1.2 },
											{ -1.8,-0.2,6.3,13.9,19.5,23.3,26.9,25.9,22.1,16.4,5.6,-1.9 },
											{ -4.0,-1.6,8.1,13.0,18.2,23.1,27.8,28.8,21.5,13.1,7.8,-0.6 },
										};
	
	printf("[Temperature Data]\n");
	printf("Year index :\t");
	for (int i = 0; i < MONTH; ++i) {
		printf("%d\t", i + 1);
	}
	printf("\n");

	for (int j = 0; j < YEARS; ++j) {
		printf("Year %d\t:\t", j);
		for (int i = 0; i < MONTH; ++i) {
			printf("%.1f\t", temperature[j][i]);
		}
		printf("\n");
	}
	printf("\n");


	printf("[Yearly average temperatures of 3 years]\n");
	for (int j = 0; j < YEARS; ++j) {
		double sum = 0;
		printf("Year %d : average temperature = ", j);
		for (int i = 0; i < MONTH; ++i) {
			sum += temperature[j][i];
		}
		printf("%.1f\n", sum / (double)MONTH);
	}
	printf("\n");


	printf("[Monthly average temperatures of 3 years]\n");
	printf("Year index :\t");
	for (int i = 0; i < MONTH; ++i) {
		printf("%d\t", i + 1);
	}
	printf("\n");

	printf("Avg temps  :\t");
	for (int j = 0; j < MONTH; ++j) {
		double sum = 0;
		for (int i = 0; i < YEARS; ++i) {
			sum += temperature[i][j];
		}
		printf("%.1f\t", sum / (double)YEARS);
	}
	printf("\n\n");

	return 0;
}