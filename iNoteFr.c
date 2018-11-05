#include <stdio.h>

void vidTAccModeToPointerAndArray(void);
void main(void)
{
	vidTAccModeToPointerAndArray();
}

void vidTAccModeToPointerAndArray(void)
{
	char *p = "abcdef";
	char a[] = "123456";
	int b[5] = {1,2,3,4,5};
	int *ptr =(int*)(&b + 1);
	/*1. Address is same for the pointer access mode and index access mode*/
	printf("*(p+4)=> ");
	if ((putchar(*(p+4)) != EOF) && (putchar(p[4])))
	{
		printf("\n");
	}
	else
	{
		/*have error while putting character on the output terminal*/
	}
	/*2. Operation with index always be parsed as operation with the pointer by the compiler*/
	/*a[4]=> &a[0] + 4x offsetOftype*/
	printf("a[4]=> %c\t *(a+4)=>%c\n", a[4], *(a+4));
	/*3. &b is the header address of the array, &b+1=> address(b)+offset(array)=>next array address*/
	/*b is the first element adress, b+1=>address(b[0])+offset(int)*/
	printf("*(b+1)=>%d\t *((int*)(&a+1) - 1)=>%d\n", *(b+1), *(ptr - 1));

} 