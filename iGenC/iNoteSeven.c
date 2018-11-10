/*1. The memory outline of the 2D array*/
/*2. The address of the *(*(a+i)+j)=>a[i][j]: a+i*sizof(char)*j+j*sizof(char)*/

#include <stdio.h>

void vidT2DArr();

void main(void)
{
	vidT2DArr();
}
void vidT2DArr()
{
	/*3. It's wrong to use the bracket()*/
	int a[3][2]={(0,1),(2,3),(4,5)};
	int b[3][2] = {{0,1}, {2,3}, {4,5}};
	int *p1 = a[0];
	int (*p2)[2] = &b[0]; /*the header address of the array b[0],p2 pointer to an array*/
	int *p3 = &b[0][0]; /*the address of the array b[0] first element, p3 pointer to an element within the array */
	/*p1[0] = p1[0][0]; *(p1+1)=P1[0][1]*/
	printf("%d\t %d\t %d\n",p1[0], *(p1+1), a[1][0]);
	/*p2=&b[0]=&b[0][0]*/
	printf("%x=>%x:%d\t %x:%d=%d!=%d\n", p2, p3, *p2[0], (p2+1), *(p2+1)[0], p2[1][0], *(p3+1));
}
