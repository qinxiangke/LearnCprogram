/*1. The memory outline of the 2 level pointer*/
/*2. To get the final data with consecutive two unlock operations '**'*/

#include <stdio.h>

void vidTest2LvlPtr();

void main(void)
{
	vidTest2LvlPtr();
}
void vidTest2LvlPtr()
{
	char ch ='A';
	char *p = &ch;
	char **p2 = &p;
	printf("p=&ch:%x=%x\t*p=ch:%c=%c, p2=&p:%x=%x\t*p2=p:%x=%x, **p2=*p:%c=%c\n", p,&ch, *p,ch, p2,&p, *p2,p, **p2,*p);
}
