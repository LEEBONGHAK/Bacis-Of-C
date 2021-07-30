#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <limits.h>		// CHAR_BIT
#include <stdbool.h>

void char_to_binary(unsigned char uc);
void print_binary(char* data, int bytes);		//Note: extended for any sizes

int main() {
	struct items {
		bool has_sword : 1;	// : number means bits to use!
		bool has_shield : 1;
		bool has_potion : 1;
		bool has_guntlet : 1;
		bool has_hammer : 1;
		bool has_key : 1;
		bool has_ring : 1;
		bool has_amulet : 1;
	} item_flag;

	item_flag.has_sword = 1;	// flags = flags | MASK_SWORD
	item_flag.has_shield = 1;
	item_flag.has_potion = 0;
	item_flag.has_guntlet = 1;
	item_flag.has_hammer = 0;
	item_flag.has_key = 0;
	item_flag.has_ring = 0;
	item_flag.has_amulet = 0;

	printf("Size = %zd byte\n\n", sizeof(item_flag));


	print_binary((char*)&item_flag, sizeof(item_flag));
	printf("\n");


	if (item_flag.has_key == 1) {		// if ((flags & MASK_KEY) == MASK_KEY) {
		printf(">> You can enter.\n");
	}
	else {
		printf(">> You can not enter.\n");
	}

	item_flag.has_key = 1;

	if (item_flag.has_key == 1) {
		printf(">> You can enter.\n");
	}
	else {
		printf(">> You can not enter.\n");
	}
	printf("\n");


	union {
		struct items bf;
		unsigned char uc;
	} uni_flag;

	uni_flag.uc = 0;
	uni_flag.bf.has_amulet = true;
	uni_flag.uc |= (1 << 4);

	print_binary((char*)&uni_flag, sizeof(uni_flag));
	printf("\n");



	/* KNK DOS example */
	struct file_time {
		unsigned int seconds : 5;		// 2^5 = 32, (0 ~ 29) 30 * 2 seconds
		unsigned int minutes : 6;		// 2^6 = 64, (0 ~ 59) 60 minutes
		unsigned int hours	 : 5;		// 2^5 = 32, (0 ~ 23) 24 seconds
	};

	struct file_data {
		unsigned int day	: 5;		// 2^5 = 32, 0 ~ 31
		unsigned int month	: 4;		// 2^4 = 16, 1 ~ 12
		unsigned int year	: 7;		// 2^7 = 128, 1980 ~
	} fd;

	/* 1988 12 28 */
	fd.day = 28;
	fd.month = 12;
	fd.year = 8;

	printf("Day %u, Month %u, Year %u\n", fd.day, fd.month, fd.year);
	//scanf("%d", &fd.day);		// WRONG - bit-field는 사용 불가


	return 0;
}

void char_to_binary(unsigned char uc) {
	const int bits = sizeof(unsigned char) * CHAR_BIT;
	for (int i = bits - 1; i >= 0; i--) {
		printf("%d", (uc >> i) & 1);
	}
}

void print_binary(char* data, int bytes) {
	for (int i = 0; i < bytes; ++i) {
		char_to_binary(data[bytes - 1 - i]);
	}
	printf("\n");
}