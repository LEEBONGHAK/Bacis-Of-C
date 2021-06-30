#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	int n = 1, i = 1;
	int j;

	// 전통적인 방법(거의 사용하지 않음)
label:
	printf("%d\n", n);
	n = n + 1;

	if (n == 10) goto out;

	goto label;

out:

	// loop 1
	while (i < 10) {
		printf("%d\n", i);
		i = i + 1;
	}

	// loop 2
	for (j = 1; j < 10; j++) {
		printf("%d\n", j);
	}

	return 0;
}