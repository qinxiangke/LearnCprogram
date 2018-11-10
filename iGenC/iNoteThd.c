#include <stdio.h>
/*1. size of the empty struct*/
struct student
{
	char ch;
};
/*2. no memory occupy for the array a while declared in struct firstly*/
/*3. flexible array occupy the heap allocated, isn't belong the struct's memory range*/
typedef struct stu_type{
	int i;
	int a[];
}type_a;

/*4. size if the union object must be big enough to store the longgest member*/
union StateMachine
{
	char ch;
	int number;
	char *str;
	double exp;
};
/*7. size of enum is same as int */
/*8. the range of enum's value is known. defaulty begin with const 0, also define with specific value*/
enum Color
{
	GREEN = 1,
	RED,
	BLUE
}ColorVal;

void vidTestEnum(void)
{
	printf("size for the enum: %d\n", sizeof(ColorVal));
}

void vidTestKSize(void)
{
	type_a *p = NULL;
	printf("size for empty struct: %d\n", sizeof (struct student));
	printf("size for the flexible array: %d\n", sizeof(type_a));
	p = (type_a*)malloc(sizeof(type_a) + 100*sizeof(int));
	printf("size for the flexible array: %d\n", sizeof(type_a));
	free(p);
}
void vidTestUnion(void)
{
	/*5. only one of them will be used*/
	/*6. data impacted by big-end/small-end mode*/
	union
	{
		int i;
		char a[2];
	}*p,u;
	p = &u;
	p->a[0] = 0x39;
	p->a[1] = 0x38;
	printf("size for union: %d\n", sizeof (union StateMachine));
	printf("u.i => %x\n", p->i);
}

int i32CheckSystem()
{
	union check
	{
		int i;
		char ch;
	}c;
	c.i = 1;
	return (c.ch == 1);
}
void main(void)
{
	vidTestEnum();
	vidTestKSize();
	vidTestUnion();
	printf("%d\n", i32CheckSystem());
}
