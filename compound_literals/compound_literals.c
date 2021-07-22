#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#define MAXTITL 41
#define MAXAUTL 31

struct book {
	char title[MAXTITL];
	char author[MAXAUTL];
	//char* title;			// Not recommended
	//char* author;			// Not recommended
	float price;
};

struct rectangle {
	double width;
	double height;
};

double rect_area(struct rectangle r);
double rect_area_ptr(struct rectangle* r);

// 복합 리터럴(Compound literals) : 구조체의 값을 임시로 사용할 때 편하게 사용 가능
int main() {
	struct book book_to_read = { "Crime and Punishment", "Fyodor Dostoyevsky", 11.25f };

	/*
		Compound literals
		- Temporary structure values
	*/

	// 구조체의 값을 바꾸는 방법
	//book_to_read = { "Alice in Wonderland", "Lewis Carroll", 20.3f };		// Error

	// 방법 1
	strcpy(book_to_read.title, "Alice in Wonderland");
	strcpy(book_to_read.author, "Lewis Carroll");
	book_to_read.price = 20.3f;

	// 방법 2
	struct book book2 = { "Alice in Wonderland", "Lewis Carroll", 20.3f };
	book_to_read = book2;

	// 방법 3 - 복합 리터럴(Compound literals)
	book_to_read = (struct book){ "Alice in Wonderland", "Lewis Carroll", 20.3f };

	printf("%s %s\n\n", book_to_read.title, book_to_read.author);



	// 응용
	struct rectangle rec1 = { 1.0, 2.0 };
	double area = rect_area(rec1);
	area = rect_area((struct rectangle) { 1.0, 2.0 });

	area = rect_area_ptr(&(struct rectangle) { .height = 3.0, .width = 2.0 });		// Designated initializer
	printf("%f\n", area);

	return 0;
}

double rect_area(struct rectangle r) {
	return r.width * r.height;
}

double rect_area_ptr(struct rectangle* r) {
	return r->height * r->width;
}