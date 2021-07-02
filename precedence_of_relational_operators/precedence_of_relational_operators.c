#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	int x = 1, y = 2, z;

	// ()을 통해 우선 순위를 알려주는 것 
	// 우선 순위가 같으면 왼쪽에서 오른쪽으로
	x > y + 2;
	x > (y + 2);

	x = y > 2;
	x = (y > 2);

	z = x > y;
	z = (x > y);

	x != y == z;
	(x != y) == z;

	// ref : Google 'Operators Precedence in C'

	return 0;
}