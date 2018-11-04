#include <stdio.h>
#define LOOP_COUNTER (unsigned int)(3)
/*1. static global variable or function aren't allowed to be accessed from other files*/
static int i32GStaticV;
static void vidTestGStaticV(void);

void vidTestLocStaticV(void);

void main(void)
{
	int i32Count = 0;
	/*what is the default value for uninitial global static variable*/
	printf("Default value is %d\n", i32GStaticV);
	for (i32Count = 0; i32Count < LOOP_COUNTER; i32Count++)
	{
		vidTestGStaticV();
		vidTestLocStaticV();
	}
	printf("After looping, value is %d for global static value\n", i32GStaticV);
}

void vidTestGStaticV(void)
{
	i32GStaticV = 0;
	i32GStaticV++;
}
/*2. static local variable stored in static memory,won't be destroied after function exiting*/
void vidTestLocStaticV(void)
{
	static int i32LocStaticV = 5;
	i32LocStaticV++;
	printf("After looping, value is %d for local static value\n", i32LocStaticV);
}
