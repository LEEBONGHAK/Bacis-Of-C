#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void count() {
	int ct = 0;
	printf("count = %d %lld\n", ct, (long long)&ct);
	ct++;
}

void static_count() {
	static int ct = 0;		// initialized only once!
	printf("count = %d %lld\n", ct, (long long)&ct);
	ct++;
}

//int func(static int i) {	// Warning (Error in GCC)
//
//}


void count_caller() {
	count();
}

void static_count_caller() {
	static_count();
}


int* pointer_count() {			// 하지 않는 것을 권장 (아주 좋지 않음)
	int ct = 0;
	printf("count = %d %lld\n", ct, (long long)&ct);
	ct++;

	return &ct;
}

int* pointer_static_count() {	// 권장하진 않지만 가능은 함(고정된 자리를 가지고 있기 때문)
	static int ct1 = 0;	
	printf("count = %d %lld\n", ct1, (long long)&ct1);
	ct1++;

	return &ct1;
}

int main() {
	count();
	count();
	count();
	count_caller();
	printf("\n");

	static_count();
	static_count();
	static_count();
	static_count_caller();
	printf("\n");

	printf("%lld\n", (long long) pointer_count());			// warning C4172 : returning address of local variable or temporary : ct
	printf("%lld\n", (long long) pointer_static_count());

	return 0;
}