#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 41

// structure declaration
struct person {			// 'person' is a tag of structure 
	char name[MAX];		// member
	int age;			// member
	float height;		// member
};

/*
struct person
{
	...
};
*/

int main() {
	int flag;		// Receives return value of scanf()

	/* Structure variable */
	struct person genie;

	/*
		dot(.) is structure membership operator
		(member access operator, member operator)
	*/

	strcpy(genie.name, "Will Smith");
	//strncpy(genie.name, "Will Smith", MAX);

	genie.age = 1000;

	// dot(.) has higher precedence than &
	flag = scanf("%f", &genie.height);		// &(genie.height)
	printf("%f\n", genie.height);



	/* Initialization */
	struct person princess = { "Naomi", 18, 160.0f };		// 주의점) 순서가 틀리면 안됨

	struct person princess2 = {
		"Naomi Scott",
		18,
		160.f
	};

	strcpy(princess.name, "Naomi Scott");
	princess.age = 18;
	princess.height = 160.0f;



	/* Designated initializers - dot(.)을 이용해 순서 상관 없이 초기화 가능 */
	struct person beauty = {
		.age = 19,
		.name = "Bell",
		.height = 150.0f
	};

	//struct person beauty = { .age = 19, .name = "Bell", .height = 150.0f };	// 가독성이 안좋은 편



	/* Pointer to a structure variable and dynamic storage allocation */
	struct person* someone;

	someone = &genie;
	//somone = (struct person*)malloc(sizeof(struct person));		// and free later



	/* Indirect member(ship) operator (or structure pointer operator) */
	someone->age = 1001;	// arrow(->) operator
	printf("%s %d\n", someone->name, (*someone).age);



	/* Structure declarations in a function */
	struct book {
		char title[MAX];
		float price;
	};



	/* No tag - 잠깐 쓰고 말 구조체일 경우 사용 */
	struct {
		char fram[MAX];
		float price;
	} apple, apple2;

	struct {
		char fram[MAX];
		float price;
	} apple3;


	strcpy(apple.fram, "Trade Joe");
	apple.price = 1.2f;

	strcpy(apple2.fram, "Safeway");
	apple2.price = 5.6f;



	/* typedef and structure */
	typedef struct person my_person;
	my_person p3;

	typedef struct person person;	// 많이 사용 (struct 를 치지 않아도 됨)
	person p4;

	typedef struct {		// 이거도 많이 사용
		char name[MAX];
		char hobby[MAX];
	} friend;

	friend f4;

	return 0;
}