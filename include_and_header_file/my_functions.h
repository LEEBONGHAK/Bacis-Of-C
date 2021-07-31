#pragma once	// ������� (header guard)

/* 
	[�������(header guard)�� ���� ��� �ߺ� include ����]
	
	A.h�� B.h�� include�ϰ� main.c���� A.h�� B.h��
	��� include�Ѵٸ� main.c������ A.h�� B.h�� ���ؼ�
	�� �� �� include�Ǵ� ���°� ��
	=> ������尡 �̷��� ���ø� ��������
	
	* �������� ��Ŭ��� ����(include guard)��� �Ҹ���.
*/

//#ifndef __MY_FUNCTIONS__		// ���� header guard�� �ϱ� ���� ���
//#define __MY_FUNCTIONS__

extern int status;

static int si = 0;

extern int add(int a, int b);

static int multiply(int a, int b) {
	return a * b;
}

//int subtract(int a, int b)
inline int subtract(int a, int b) {
	return a - b;
}

void print_status();
void print_address();

//#endif