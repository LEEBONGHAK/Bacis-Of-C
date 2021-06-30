#define _CRT_SECURE_NO_WARNINGS

// 전처리기를 사용한 기호적 상수(symbolic constant) 선언, 대문자로 선언하는 것이 관습
#define PI 3.141592f 
#define AI_NAME "Jarvis"

#include <stdio.h>

int main() {
	// 전처리기를 사용하지 않고 기호적 상수를 사용할 경우 const를 사용해 선언
	// 요즘은 이러한 방법을 권장
	// const float pi = 3.141592f;

	float radius, area, circum;

	printf("I'm %s.\n", AI_NAME);
	printf("Please, input radius\n");

	scanf("%f", &radius);

	area = PI * radius * radius; // area = Pi * r^2
	circum = 2 * PI * radius; // circum = 2 * Pi * r

	// sphere area, sphere volume, ... -> symbolic constant를 사용하지 않으면 불편

	printf("Area is %f\n", area);
	printf("Circumference is %f\n", circum);

	// TODO : wrong usage, strings, const

	return 0;
}