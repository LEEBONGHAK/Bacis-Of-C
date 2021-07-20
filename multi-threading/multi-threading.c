#define _CRT_SECURE_NO_WARNINGS

// c 언어 표준에는 멀티 쓰레딩을 제공하지 않고, 운영체제에서 제공하는 api를 사용해야 함
// -> 운영체제에 따라 사용하는 프로그램 기술이 달라짐
#include <stdio.h>
#include <Windows.h>

//_Atomic int acnt = 0;		// NA

DWORD WINAPI ThreadFunc(void* data) {
	int n = 1;
	Sleep(1000);

	//acnt += n;		// NA
	printf("Printing from Thread \n");
	return 0;
}


// Thread : 프로그램 실행시켜 나가는 흐름
// Multi Thread : main thread가 다른 thread를 만들어 프로그램을 실행시키는 것
int main() {
	HANDLE thread = CreateThread(NULL, 0, ThreadFunc, NULL, 0, NULL);	// thread 생성

	if (thread) {
		WaitForSingleObject(thread, INFINITE);		// thread 종료까지 대기 후 합류
	}
}

/*	at gcc compiler
 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>		// sleep().
#include <pthread.h>
#include <stdatomic.h>

_Atomic int acnt = 0;		// atomic type qualifer (C11) - 동일한 전역 변수를 여러 thread가 사용할 경우 발생하는 문제를 방지하기 위해 사용

// A normal C function that is excuted as a thread
// when its name is specified in pthread_create()
void* myThreadFun(void* vargp) {
	int n = 1;		// thread storage duration
	for (int j = 0; j < 10; j++) {
		sleep(1);
		acnt += n;			// atomic 연산은 일반적인 연산보다 느림
		printf("Printing from Thread %d %llu\n", acnt, (unsigned long long) & n);
	}

	return NULL;
}

int main() {
	pthread_t thread_id1, thread_id2;	// thread 식별

	printf("Before Thread\n");

	pthread_create(&thread_id1, NULL, myThreadFun, NULL);		// thread 생성
	pthread_create(&thread_id2, NULL, myThreadFun, NULL);		// thread 생성

	pthread_join(thread_id1, NULL);		// thread가 main thread에 합류
	pthread_join(thread_id2, NULL);		// thread가 main thread에 합류

	printf("After Thread\n");
	printf("Atomic %d\n", acnt);
	
	return 0;
}


To compile
	$ gcc <file-name.c> -o <output-file-name> -lpthread
To run
	$ ./<output-file-name>
*/