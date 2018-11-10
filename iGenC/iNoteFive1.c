#include <stdio.h>

int p[100];
char *a = "abcdefg";

void InitArray()
{
    int i32Counter;
    for (i32Counter = 0; i32Counter < 100; i32Counter)
    {
        p[i32Counter] = i32Counter;
    }
}
