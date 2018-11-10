/*Ex: how to use the pointer to function*/
/*build consistent identifier for many module which desire to implement the same function*/
/* "*(int*)&p =(int)Function" */
/*Ex: how to use the function pointer array*/
/*Ex: how to use the pointer which pointer to a function pointer array*/
/*for example: char* (*(*pf)[3])(char* p)*/
#include <stdio.h>

char *fun(char *p1, char *p2)
{
    int i = 0;
    i = strcmp(p1, p2);
    if( 0 == i)
    {
        return p1;
    }
    else
    {
        return p2;
    }
}

void vidTestPtrFuc(void)
{
    char* (*pf)(char *p1, char *p2);
    pf = &fun;
    (*pf)("aa", "bb");
}

char *fun1(char *p)
{
    printf("%s\n", p);
    return p;
}
char *fun2(char *p)
{
    printf("%s\n", p);
    return p;
}
char *fun3(char *p)
{
    printf("%s\n", p);
    return p;
}

void vidTestFunPtrArray(void)
{
    char *(*pf[3])(char*);
    pf[0] =fun1;
    pf[1] = &fun2;
    pf[2] =fun3;
    pf[0]("fun1");
    pf[1]("fun2");
    pf[2]("fun3");
}   

void vidTestPtrFunPtrArray(void)
{
    char *(*a[3])(char*);
    char *(*(*pf)[3])(char *);
    pf=&a;
    a[0] =fun1;
    a[1] = &fun2;
    a[2] =fun3;
    (*pf)[0]("fun1");
    pf[0][1]("fun2");
    pf[0][2]("fun3");
}   

void main(void)
{
	vidTestPtrFuc();
    vidTestFunPtrArray();
    vidTestPtrFunPtrArray();
}
