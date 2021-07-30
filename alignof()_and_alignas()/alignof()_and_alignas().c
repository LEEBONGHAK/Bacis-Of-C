#define _CRT_SECURE_NO_WARNINGS

// 주의! visual studio에서는 지원하지 않는 코딩 -> 온라인 컴파일러 사용하기
#include <stdio.h>
#include <stdalign.h>	// C++ style alignas, alignof

int main() {
#ifdef __clang_major__
	printf("clang detected version %d.%d\n", __clang_major__, __clang_minor__);
#endif // __clang_major__

#ifdef __GNUC__
	// note that clang 3.7 declares itself as a gcc 4.2"
	printf("gcc detected version %d.%d\n", __GNUC__, __GNUC_MINOR__);
#endif // __GNUC__

	printf("Alignment of char = %zu\n", alignof(char));			// 1
	printf("alignof(float[10]) = %zu\n", alignof(float[10]));	// 4
	printf("alignof(struct{char c; int n;}) = %zu\n",
		alignof(struct { char c; int n; }));					// 4


	double dx;
	char ca;
	char cx;
	double dz;
	char cb;
	//char _Alignas(double) cz;
	//char alignas(16) cz;
	char cz;

	//printf("char alignment: %zd\n", _Alignof(char));
	//printf("double alignment: %zd\n", _Alignof(double));
	printf("char alignment: %zd\n", alignof(char));			// 1
	printf("double alignment: %zd\n\n", alignof(double));	// 8

	printf("&dx: %p %lld\n", &dx, (long long)&dx % 8);		// 0
	printf("&ca: %p %lld\n", &ca, (long long)&ca % 8);		// 4
	printf("&cx: %p %lld\n", &cx, (long long)&cx % 8);		// 5
	printf("&dz: %p %lld\n", &dz, (long long)&dz % 8);		// 0
	printf("&cb: %p %lld\n", &cb, (long long)&cb % 8);		// 6
	printf("&cz: %p %lld\n", &cz, (long long)&cz % 8);		// 7

	unsigned char alignas(long double) c_arr[sizeof(long double)];


	return 0;
}