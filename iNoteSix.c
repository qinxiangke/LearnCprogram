/*1. The memory outline of the pointer array*/
/*2. THe memory outline of the array pointer*/

#include <stdio.h>

struct Test {
	int Num;
	char *pcName;
	short sDate;
    char cha[2];
    short sBa[4];
}* p;
void ArrPtrMixTest();

void main(void)
{
	ArrPtrMixTest();

}
void ArrPtrMixTest()
{
	char a[5] = {'A', 'B', 'C', 'D'};
	char (*p1)[3] = &a;
	char (*p2)[3] = a;

	int b[4] = {1,2,3,4};
	int *ptr1 = (int *)(&b + 1);	/*Get &b[4]*/
	int *ptr2 = (int *)((int)b + 1); /*Get &b[1]*/
	printf ("%x, %x\n", ptr1[-1], *ptr2);

	printf("p1 p1+1=>%x\t%x  p2 p2+2 =>%x\t%x\n", p1, p1+1, p2, p2+1);
	printf("size for struct test=>%d \tp=> %x\tp+0x1=>%x \n", sizeof(struct Test),p, p+1);
}
