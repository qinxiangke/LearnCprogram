#include <stdio.h>

/*7. Macro act as the replace of a const or a string*/
#define ERROR_POWEROFF -1
/*'\' is regarded as the continue line symbol without any char following it*/
#define PATH C:\Users\Kevin\
project

/*6. shouldn't skip the bracket*/
#define SUM(x) ((x) + (x))
/*3. '##' concatenate two symbols */
#define XNAME(n) x##n
/*4. '#' within the string can expand the symbol after it*/
#define SQR(x) printf("The square of "#x" is %d.\n",((x)*(x)));

/*each memember is aligned with its natual boundry,the compiler don't need align automaticly*/
struct test1Align{
	char c1;
	char c2;
	short s;
	int i;
};
/*5. change the default align from the complier*/
#pragma pack(8)
struct TestStruct4
{
	char a;
	long b;
};
struct TestStruct5
{
	char c;
	struct TestStruct4 d;
	double e;
};
#pragma pack()

int main(void)
{
	int xn = 0; /**/
	int *p = NULL;/*C language is case-sensitive*/
	int i = 10; /*i is the name of 4 bytes memory*/
	/*1.Storing the value in the specific memory*/
	*(int *)&i = 12;	/*Don't miss the prefix 0x*/
	printf("The address of i : %x\n", &i);
	printf("The value stored in i : %d\n", i);

	/*2.the difference between int *p = NULL and *p = NULL*/
	printf("The value of p is :%x\n", p);
	p = &i;	/*NULL is reprient for the address,that is not recommond*/
	*p = NULL;
	/* '*' means to unlock the memory, then read or write the memory*/
	printf("The value sotred in the memory pointed by p is %d\n", *p); 
	
	printf("The expand of MACRO 'XNAME': %d\n", XNAME(n));
	SQR(8);
	/*memory alignment is to avoid the addional memory bus period*/
	printf("Length of the struct 'test1Align': %d\t"
	"Length of the struct 'TestStruct4': %d\t"
	"Length of the struct 'TestStruct5': %d\n",
	sizeof(struct test1Align), sizeof(struct TestStruct4), sizeof(struct TestStruct5));		

	printf("SUM(x): %d\n", SUM(5));
}

