#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	// 5.3 더하기, 빼기, 부호 연산자들
	printf("%d\n", 1 + 2);

	int income, salary, bonus;

	income = salary = bonus = 100; // triple assignment

	salary = 100;
	bonus = 30;

	income = salary + bonus; // L-value vs R-value

	int takehome, tax;
	tax = 20;
	takehome = income - tax;

	int a, b;
	a = -7; 
	b = -a; // 부호도 operator
	b = +a; // + does nothing

	// 1.0f + 2; // float + int => float (promotion / 승진)


	// 5.4 곱하기 연산자
	double seed_money, target_money, annual_interest;
	int year_count = 0;

	printf("Input seed money : ");
	scanf("%lf", &seed_money);
	printf("Input target money : ");
	scanf("%lf", &target_money);
	printf("Input annual interest (%%) : ");
	scanf("%lf", &annual_interest);

	while (seed_money <= target_money) {
		// seed_money = seed_money + seed_money * (annual_interest / 100.0);
		seed_money += seed_money * (annual_interest / 100.0);
		// year_count = year_count + 1;
		// year_count += 1;
		year_count++;
		printf("%f\n", seed_money);
	}

	printf("I takes %d years\n", year_count);


	// 5.5 나누기 연산자
	printf("Integer divisions\n");
	printf("%d\n", 14 / 7); // 2
	printf("%d\n", 7 / 2); // 3.5 in floating division
	printf("%d\n", 7 / 3); // 2.333 in floation division
	printf("%d\n", 7 / 4); // 1.75 in floating division
	printf("%d\n", 8 / 4); // 2

	printf("\nTruncating toward zero (C99)\n");
	printf("%d\n", -7 / 2); // -3.5 in floating division
	printf("%d\n", -7 / 3); // -2.333 in floation division
	printf("%d\n", -7 / 4); // -1.75 in floating division
	printf("%d\n", -8 / 4); // -2
	
	printf("\nFloating divisions\n");
	printf("%d\n", 9.0 / 4.0); // 2.250000
	printf("%d\n", 9.0 / 4); // Note: 4 is integer, but same result
	// 가급적 같은 자료형끼리 계산하는 것이 좋음
	

	// 5.7 나머지 연산자 (Modulus Operator)
	int second = 0, minute = 0, hour = 0;

	printf("Input second : ");
	scanf("%d", &second);

	// TODO : second -> hour, minute, second
	hour = second / 3600;
	minute = (second % 3600) / 60;
	second = (second % 3600) % 60;

	printf("%d hours, %d minutes, %d seconds\n", hour, minute, second);
	printf("Good bye\n");

	int div, mod;

	div = 11 / 5;
	mod = 11 % 5;
	printf("div = %d, mod = %d\n", div, mod); // 2, 1

	div = 11 / -5;
	mod = 11 % -5;
	printf("div = %d, mod = %d\n", div, mod); // -2, 1

	div = -11 / -5;
	mod = -11 % -5; // first operand is negative
	printf("div = %d, mod = %d\n", div, mod); // 2, -1

	div = -11 / 5;
	mod = -11 % 5; // first operand is negative
	printf("div = %d, mod = %d\n", div, mod); // -2, -1


	// 5.8 증가 / 감소 연산자
	int increase = 0;
	increase++; // increase = increase + 1 or increase += 1
	printf("%d\n", increase); // 1

	++increase; // increase = increase + 1 or increase += 1
	printf("%d\n", increase); // 2

	double increase1 = 0;
	increase1++;
	printf("%f\n", increase1); // 1.000000

	++increase1;
	printf("%f\n", increase1); // 2.000000

	int count = 0;
	
	while (count++ < 10) // count++ or ++count
	{
		printf("%d\n", count); // count++ or ++count
	}

	int increase2 = 1, increase3 = 1;
	int increase2_post, pre_increase3;

	increase2_post = increase2++;
	pre_increase3 = ++increase3;

	printf("%d %d\n", increase2, increase3); // 2 2
	printf("%d %d\n", increase2_post, pre_increase3); // 1 2

	int increase4 = 3;
	int increase5 = 2 * --increase4;
	printf("%d %d\n", increase4, increase5); // 2 4

	increase4 = 1;
	increase5 = 2 * increase4--;
	printf("%d %d\n", increase4, increase5); // 0 2

	/* very high precedence */
	int x, y, z;
	x = 3, y = 4;
	z = (x + y++) * 5; // (x + y)++ or x + (y++) ?
	printf("%d %d %d\n", x, y, z); // 3 5 35

	/* ++ and -- affect modifiable L-values */
	x = 1, y = 1, z = 0;
	z = x * y++; // (x) * (y++), not (x * y)++
	// z = (x * y)++; // error
	// z = 3++; // error

	/* Bad practices - 명확한 경우에 쓰는 것이 좋음 */
	int n = 1;
	printf("%d %d\n", n, n * n++); // 여러번 사용할 경우 시스템에 따라 결과가 달라질 수 있음
	x = n / 2 + 5 * (1 + n++);
	y = n++ + n++;

	return 0;
}