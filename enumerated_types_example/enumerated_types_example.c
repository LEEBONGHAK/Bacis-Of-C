#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>		// strcmp()
#include <stdbool.h>

enum spectrum { red, orange, yellow, green, blue };
const char* colors[] = { "red", "orange", "yellow", "green", "blue" };

#define LEN		30

int main() {
	char choice[LEN] = { 0, };
	enum spectrum color;
	bool color_is_found = false;

	while (1) {
		printf("Input a color name (empty line to quit)\n");
		
		if (scanf("%[^\n]%*c", choice) != 1) {
			break;
		}

		for (color = red; color < blue; color++) {
			if (strcmp(choice, colors[color]) == 0) {
				color_is_found = true;
				break;
			}
		}

		if (color_is_found) {
			switch (color)
			{
			case red:
				printf("Red roses\n");
				break;
			case orange:
				printf("Orange sunset\n");
				break;
			case yellow:
				printf("Yellow sunflowers\n");
				break;
			case green:
				printf("Green apples\n");
				break;
			case blue:
				printf("Blue ocean\n");
				break;
			}
		}
		else {
			printf("Please try different color %s.\n", choice);
		}

		color_is_found = false;
	}

	printf("Good bye!\n");

	return 0;
}