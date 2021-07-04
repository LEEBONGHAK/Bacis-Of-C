#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	// 종합 소득세 계산 예제 (2018년도 기준)
	const double BASE1 = 12000000.0;
	const double BASE2 = 46000000.0;
	const double BASE3 = 88000000.0;
	const double BASE4 = 150000000.0;
	const double BASE5 = 300000000.0;
	const double BASE6 = 500000000.0;

	const double RATE1 = 0.06;
	const double RATE2 = 0.15;
	const double RATE3 = 0.24;
	const double RATE4 = 0.35;
	const double RATE5 = 0.38;
	const double RATE6 = 0.40;
	const double RATE7 = 0.42;

	double income = 0.0;	// annual income
	double tax = 0.0;

	printf("Input your income : ");
	scanf("%f", &income);

	income -= 1500000;		// 기본 공제

	if (income <= BASE1) {
		tax = income * RATE1;
	}
	else if (income <= BASE2) {
		tax = BASE1 * RATE1 + (income - BASE1) * RATE2;
	}
	else if (income <= BASE3) {
		tax = BASE1 * RATE1 + (BASE2 - BASE1) * RATE2 + (income - BASE2) * RATE3;
	}
	else if (income <= BASE4) {
		tax = BASE1 * RATE1 + (BASE2 - BASE1) * RATE2 + (BASE3 - BASE2) * RATE3 + (income - BASE3) * RATE4;
	}
	else if (income <= BASE5) {
		tax = BASE1 * RATE1 + (BASE2 - BASE1) * RATE2 + (BASE3 - BASE2) * RATE3 + (BASE4 - BASE3) * RATE4 + (income - BASE4) * RATE5;
	}
	else if (income <= BASE6) {
		tax = BASE1 * RATE1 + (BASE2 - BASE1) * RATE2 + (BASE3 - BASE2) * RATE3 + (BASE4 - BASE3) * RATE4 + (BASE5 - BASE4) * RATE5 + (income - BASE5) * RATE6;
	}
	// else if (income > BASE6) {
	else {
		tax = BASE1 * RATE1 + (BASE2 - BASE1) * RATE2 + (BASE3 - BASE2) * RATE3 + (BASE4 - BASE3) * RATE4 + (BASE5 - BASE4) * RATE5 + (BASE6 - BASE5) * RATE6 + (income - BASE6) * RATE7;
	}

	printf("Your tax is %f\n", tax);
	printf("Your income after tax deduction is %f\n", income - tax);

	return 0;
}