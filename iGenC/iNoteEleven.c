/* no memory allocated which the pointer point to*/
/* Memory allocation is not enough*/
/* check the availability of the pointer before being used*/
/* using ASSERT() to localize the error*/
/*1. check if memory allocation is done*/
/*2. check if memory space is enough*/
/*3. check if point is initialized*/
/*4. check if memory access is beyond the boundry*,Ex:(]used in for statement*/
/*momory leakage:*/
/*1.how to use malloc, */
/*who is assigned to?*/ 
/*what size is assigned?*/
/*If the remaining memory space is enough?*/
/*What is the memory used for in future?*/
/*Where is the memory space?*/
/*Ex:(void*) malloc(int size) */
/*2. how to use free*/
/*disconnect to the specific memory space*/
/*only free once*/
/*p=Null: re-init the pointer after free*/


#include <stdio.h>

struct student
{
    char *name;
    int score;
}stu,*pstu;

void vidTestNoMomoryAlloca(void)
{
    //strcpy(stu.name, "Jimmy");/*no memory to the pointer 'name'*/
	pstu= (struct student*)malloc(sizeof(struct student));
    /*no memory to the pointer 'name',only 4 bytes space storing the point variable*/
	pstu->name = (char *)malloc(10);
	strcpy(pstu->name, "Jimmy");
    pstu->score = 99;
    free(pstu);
}
void main(void)
{
	vidTestNoMomoryAlloca();
}
