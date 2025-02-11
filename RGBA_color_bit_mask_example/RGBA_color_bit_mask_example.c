﻿#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define BYTE_MASK 0xff		// 11111111 (binary), 255 (decimal)

int main() {
	unsigned int rgba_color = 0x66CDAAFF;
	// 4 bytes, medium aqua marine	(102, 205, 170, 255)

	unsigned char red, green, blue, alpha;

	// Use right shift >> operator
	alpha = rgba_color & BYTE_MASK;
	blue = (rgba_color >> 8) & BYTE_MASK;	// TODO:
	green = (rgba_color >> 16) & BYTE_MASK;	// TODO:
	red = (rgba_color >> 24) & BYTE_MASK;	// TODO:

	printf("%hhu\n", BYTE_MASK);
	printf("(R, G, B, A) = (%hhu, %hhu, %hhu, %hhu)\n",
		red, green, blue, alpha);

	return 0;
}