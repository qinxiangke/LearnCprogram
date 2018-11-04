#include <stdio.h>
#include <string.h>

void vidTestSizeof(void);
void vidTestSign(void);

void main(void)
{
    /*1. sizeof is keyword, not function*/
    /*2. the bracket can be discarded while operand is variable, but not if operand is dataTYpe*/
    /*3. sizeof (int)*p, what's meaning?*/
    /*4. a, &a act as the beginning address of the array, sizeof will return the whole array's size*/
    vidTestSizeof();
    /*1. defautly for char type with signed, range is -128~127*/
    /*2. -1 => 0xFFFFFFFF*/
    /*3. -0 => 0x00000000*/
    /*4. +0 => 0x00000000*/
	/*5. -128 => 0xFFFFFF80*/
    vidTestSign();
}

void vidTestSizeof(void)
{
    int *p = NULL;
    int a[100];
    printf("size for the pointer variable p: %d\n",sizeof(p));
	printf("size of the memory space the pointer point to: %d\n",sizeof(*p));
    printf("size for the array variable a:%d\n", sizeof(a));
    printf("size for &a: %d\n", sizeof(&a));
    printf("size for &a[0]:%d\n", sizeof(&a[0]));
    printf("size for a[100]:%d\n", sizeof(a[100]));
}

void vidTestSign(void)
{
    int i32Error = -1;
	int i32MinusZero = (signed int)0;
	int i32PlusZero = 0;
	int i32Minus128 = -128;
	unsigned int u32Base = 10;
	signed int i32Add = -20;
    char a[1000];
	int j;
    int i;
    for(i=0; i<1000; i++)

    { 

       a[i] = -1-i; 
    }
	/*a[255] = '\0'*/
     printf("%d \t %d\n",strlen(a), a[255]);
     printf("-1: %x\t -0: %8x\t 0:%8x\t -128£º%8x\n", i32Error, i32MinusZero, i32PlusZero, i32Minus128);
	 printf("sum of unsigned and signed number is %8x=>%d\n",  u32Base + i32Add,  u32Base + i32Add);
	 for (j = 9; j >= 0; j--)
	 {
		/*do nothing*/
	 }
	 printf("After loop:%x\t %d", j,j);
}




