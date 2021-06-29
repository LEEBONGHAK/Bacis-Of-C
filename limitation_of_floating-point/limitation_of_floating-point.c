#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <float.h>
#include <math.h>

int main() {
	// round-off errors (ex1)
	float a, b;
	a = 1.0E20f + 1.0f; // 상대적으로 너무 차이가 나는 수를 더하면 작은 수가 생략됨
	// 범위가 너무 다른 수를 계산하지 않도록 주의
	b = a - 1.0E20f;
	printf("%f\n", b);


	// round-off errors (ex2)
	float c = 0.0f;
	int i;
	// 0.01 100번 더하기
	for (i = 0; i < 100; i++) {
		c = c + 0.01f;
	}
	printf("%f\n", c); // 0.999999
	// 부동소수점 표현법에서는 0.01을 정확하게 계산할 수 없기 때문에 오차가 싸여 이러한 오차 발생


	// overflow
	float max = 3.402823466e+38F;
	printf("%f\n", max);
	max = max * 100.0f;
	printf("%f\n", max); // inf -> 너무 커서 뭔지 모르겠다(overflow)


	// underflow
	float min = 1.175494351e-38F;
	printf("%e\n", min);
	min = min / 100.0f;
	printf("%e\n", min); // 0.000000 -> subnormal : 정밀도를 잃어버린 숫자(숫자가 사라져버림 / 표현이 안됨)


	// divided by 0
	float zero = 104.0f;
	printf("%f\n", zero);
	zero = zero / 0.0f;
	printf("%f\n", zero); // inf


	// arcsine
	float arcsine = asinf(1.0f);
	printf("%f\n", arcsine);

	arcsine = asinf(2.0f); // 수학적으로 arcsine의 범위를 넘어가는 값
	printf("%f\n", arcsine); // -nan(ind) => not a number

	return 0;
}