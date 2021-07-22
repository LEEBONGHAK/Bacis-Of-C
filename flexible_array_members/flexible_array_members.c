#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>			// malloc(), free(), exit()

int main() {
	/* Flexible array member (struct hack in GCC) */
	struct flex {
		size_t count;
		double average;
		double values[];		// flexible array member (last member !)
	};

	const size_t n = 3;

	// 구조체 크기 + 배열로 사용하고 싶은 길이만큼 동적 할당
	// malloc()은 일렬로 나열된 메모리를 주기 때문에 어디 있는지 확실히 알 수 있음
	struct flex* pf = (struct flex*)malloc(sizeof(struct flex) + n * sizeof(double));
	if (pf == NULL) {
		exit(1);
	}

	printf("\nFlexible array member\n");
	printf("Sizeof struct flex %zd\n", sizeof(struct flex));
	printf("Sizeof *pf %zd\n", sizeof(*pf));
	printf("Sizeof malloc %zd\n\n", sizeof(struct flex) + n * sizeof(double));

	printf("%lld\n", (long long)pf);
	printf("%lld\n", (long long)&pf->count);
	printf("%zd\n", sizeof(pf->count));
	printf("%lld\n", (long long)&pf->average);
	printf("Address of pf->values %lld\n", (long long)&pf->values);
	printf("Value of pf->values %lld\n", (long long)pf->values);
	printf("Sizeof pf->values %zd\n\n", sizeof(pf->values));

	pf->count = n;
	pf->values[0] = 1.1;
	pf->values[1] = 2.2;
	pf->values[2] = 3.3;

	pf->average = 0.0;
	for (unsigned i = 0; i < pf->count; ++i) {
		pf->average += pf->values[i];
	}
	pf->average /= (double)pf->count;

	printf("Average = %f\n\n", pf->average);



	/* Non-flexible array member */
	struct nonflex {
		size_t count;
		double average;
		double *value;		// Use malloc() - flexible array member와는 다르게 pointer 자체의 메모리를 차지함
	};

	struct nonflex nf;
	nf.value = (double*)malloc(sizeof(double) * n);		// 메모리 위치가 어디에 위치할 지 알 수 없음
	
	printf("\nNon-flexible array member\n");
	printf("Sizeof struct flex %zd\n", sizeof(struct nonflex));
	printf("Sizeof *pf %zd\n", sizeof(nf));
	printf("Sizeof malloc %zd\n\n", sizeof(struct nonflex) + n * sizeof(double));

	printf("%lld\n", (long long)&nf);
	printf("%lld\n", (long long)&nf.count);
	printf("%zd\n", sizeof(nf.count));
	printf("%lld\n", (long long)&nf.average);
	printf("Address of pf->values %lld\n", (long long)&nf.value);
	printf("Value of pf->values %lld\n", (long long)nf.value);
	printf("Sizeof pf->values %zd\n\n", sizeof(nf.value));




	/* Warning point */
	struct flex* pf2 = (struct flex*)malloc(sizeof(struct flex) + n * sizeof(double));
	if (pf2 == NULL) {
		exit(1);
	}

	//*pf2 = *pf1;		// Don't copy flexible members, use memcpy() instead
	
	free(pf);
	free(pf2);

	return 0;
}