#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>		// printf() in second.c

extern int g_int;		// ��� 1 - file scope������ �ʱ�ȭ ���� (�׷��� 2�� �̻� �ʱ�ȭ�� �Ұ���)

void temp() {
	//extern int g_int;		// ��� 2 - ����: block scope���� �ʱ�ȭ �Ұ���


	g_int += 1000;
}

void func_sec() {
	temp();
	
	//extern int g_int;		// ��� 2 - ����: block scope���� �ʱ�ȭ �Ұ���

	g_int += 7;
	printf("g_int in main() %d %p\n", g_int, &g_int);
}