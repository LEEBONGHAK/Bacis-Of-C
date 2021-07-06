#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>		// exit()

char get_choice(void);
char get_first_char(void);
int get_integer(void);
void count(void);

int main() {
	// 내가 만든 코드
	//char c;
	//int num;

	//while (1) {
	//	printf("Enter the letter of your choice:\n");
	//	printf("a. avengers		b. beep\n");
	//	printf("c. count		q. quit\n");

	//	scanf("%c", &c);

	//	while (getchar() != '\n')
	//		continue;

	//	if (c == 'q') {
	//		break;
	//	}
	//	else if (c == 'a') {
	//		printf("Avengers assemble!\n");
	//	}
	//	else if (c == 'b') {
	//		printf('\a');
	//	}
	//	else if (c == 'c') {
	//		printf("Enter an integer : \n");
	//		scanf("%d", &num);
	//		for (int i = 1; i <= num; ++i) {
	//			printf("%d\n", i);
	//		}
	//	}
	//	else {
	//		printf("Please try again\n");
	// 		continue;
	//	}

	//	
	//}


	// 강의 코드
	int user_choice;

	while ((user_choice = get_choice()) != 'q') {
		switch (user_choice) {
		case 'a':
			printf("Avengers assemble!\n");
			break;
		case 'b':
			putchar('\a');		// Beep
			break;
		case 'c':
			count();
			break;
		default:
			printf("Error with %d.\n", user_choice);
			exit(1);
			break;
		}
	}

	return 0;
}

void count(void) {
	int n, i;

	printf("Enter an integer:\n");
	n = get_integer();
	for (i = 1; i <= n; ++i) {
		printf("%d\n", i);
	}
	while (getchar() != '\n') {
		continue;
	}
}

int get_integer(void) {
	int input;
	char c;

	while ((scanf("%d", &input)) != 1) {
		while ((c = getchar()) != '\n') {
			putchar(c);
		}
		printf(" is not an integer.\nPlease try again.\n");
	}

	return input;
}

char get_choice(void) {
	int user_input;

	printf("Enter the letter of your choice:\n");
	printf("a. avengers\tb. beep\n");
	printf("c. count\tq. quit\n");

	user_input = get_first_char();

	while ((user_input < 'a' || user_input>'c') && user_input != 'q') {
		printf("Please try again.\n");
		user_input = get_first_char();
	}

	return user_input;
}

char get_first_char(void) {
	int ch;

	ch = getchar();
	while (getchar() != '\n') {
		continue;
	}

	return ch;
}