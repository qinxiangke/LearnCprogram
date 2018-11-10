
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void vidTestFunParaArray();
void vidTestFunParaPtr();

void main(void)
{
	vidTestFunParaArray();
	vidTestFunParaPtr();
}

/*size of the array is meaningless*/
void fun1(char a[10]) /*or fun1(char *p) or fun1(char a[])*/
{
	int i = sizeof(a);
	char c = a[3];
	/*3. a is parsed as the pointer which points to the first element of the array*/
	printf("sizeof a:%d\n", i);
}

void vidTestFunParaArray()
{
	/*if the whole array can be transfered*/
	char a[10] = "abcdefg";
	/*1.warning reported during the compiling as a[10] is array's element,type is char but char* required */
	/*2.to calculate the actual address of a[10] while running,it results in the memory access exception*/
	fun1(a);//fun1(a[10]);
}

void fun2(char *p)
{
	char c = p[3];
}
char* GetMemory(char *p, int num)
{
	p = (char*)malloc(num*sizeof(char));
	return (p);
}

void vidTestFunParaPtr()
{
	char *p2 = "abcdefg";
	char *str = NULL;
	/*if p2 itself can be transfered? no fun2 cann't use the p2, actually using the _p2 as the copy of the p2*/
	fun2(p2);
	/*p2 cann't be transfer to the function direclty*/
	/*uing the return to get the the header of the memory allocated automaticly*/
	/*or using "**p" 2 indirect pointer to transfer the address of the pointer not the pointer variable*/
	str = GetMemory(str, 10);
	strcpy(str, "hello");
	free(str);
}
