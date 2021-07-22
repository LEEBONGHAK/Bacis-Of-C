#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#define FUNDLEN 20

struct fortune {
	char bank_name[FUNDLEN];
	double bank_saving;
	char fund_name[FUNDLEN];
	double fund_invest;
};

double sum(double, double);
double sum2(const double*, const double*);		// const를 통해 값을 바꾸지 않을 것을 표시
double sum3(struct fortune my_fortune);
double sum4(const struct fortune* mf);			// const를 통해 값을 바꾸지 않을 것을 표시

int main() {
	struct fortune my_fortune = {
		"Wells-Fargo",
		4032.27,
		"JPMorgan Chase",
		8543.94
	};

	printf("Total : $%.2f.\n",
		sum(my_fortune.bank_saving, my_fortune.fund_invest));

	printf("Total : $%.2f.\n",
		sum2(&my_fortune.bank_saving, &my_fortune.fund_invest));

	printf("Total : $%.2f.\n", sum3(my_fortune));

	printf("Total : $%.2f.\n", sum4(&my_fortune));

	return 0;
}

double sum(double x, double y) {
	return x + y;
}

double sum2(const double* x, const double* y) {
	return *x + *y;
}

// 메모리를 더 먹음(복사할 struct를 설정해야함) -> 느려질 수 있음(struct에 따라) -> 부담
double sum3(struct fortune my_fortune) {		// 변수의 주소가 다름
	return my_fortune.bank_saving + my_fortune.fund_invest;
}

double sum4(const struct fortune *mf) {		// 더 권장됨
	return mf->bank_saving + mf->fund_invest;
}