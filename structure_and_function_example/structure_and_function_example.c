#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#define NLEN 30

struct name_count {
	char first[NLEN];
	char last[NLEN];
	int num;
};

void receive_input(struct name_count*);
void count_characters(struct name_count*);
void show_result(const struct name_count*);
char* s_gets(char* st, int n);

int main() {
	struct name_count user_name;

	receive_input(&user_name);
	count_characters(&user_name);
	show_result(&user_name);


	return 0;
}

void receive_input(struct name_count* un) {
	//int flag;
	
	printf("Input your first name:\n>> ");
	s_gets(un->first, NLEN);
	//flag = scanf("%[^\n]%*c", un->first);		// "%[^\n]%*c" : 줄바꿈이 나타날 때까지 입력하고 줄바꿈을 무시 -> 줄바꿈을 빼고 입력받음
	//if (flag != 1) {
	//	printf("Wrong input\n");
	//}

	printf("Input your last name:\n>> ");
	s_gets(un->last, NLEN);
	//flag = scanf("%[^\n]%*c", un->last);
	//if (flag != 1) {
	//	printf("Wrong input\n");
	//}
}

void count_characters(struct name_count* un) {
	un->num = strlen(un->first) + strlen(un->last);
}

void show_result(const struct name_count* un) {
	printf("Hi, %s %s. Your name has %d characters.\n", 
		un->first, un->last, un->num);
}

char* s_gets(char* st, int n) {
	char* ret_val;
	char* find;

	ret_val = fgets(st, n, stdin);
	if (ret_val) {
		find = strchr(ret_val, '\n');
		if (find) {
			*find = '\0';
		}
		else {
			while (getchar() != '\n') {
				continue;
			}
		}
	}

	return ret_val;
}