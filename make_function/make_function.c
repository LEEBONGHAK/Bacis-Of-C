#include <stdio.h>

// prototyping 또는 function declaration
void say_hello_two();

// return type이 없기 때문에 void
void say_hello(void) {
	
	printf("Hello, World!\n");

	return; // return type이 void면 return 생략가능
}

int main() {

	say_hello();
	say_hello_two();

	return 0;
}

// function definition
void say_hello_two() {

	printf("Hello, World!\n");
	printf("Hello, World!\n");
}