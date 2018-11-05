#include <stdio.h>

/*2. p is a declaration for the pointer, it is wrong to define it as an array in iNoteFive2.c*/
extern int *p; /*p[100] in iNoteFive2.c*/
extern char a[]; /*char *a = "abcdef" in iNoteFive2.c*/
/*1. this is the declaration for the function. Its definition is located in other file*/
extern void InitArray();
void vidReadArray();

void main(void)
{
	InitArray();
	vidReadArray();
}

void vidReadArray()
{
	//printf("%x=>\n", p);
	printf("=>%c\n", a[0]);
}
