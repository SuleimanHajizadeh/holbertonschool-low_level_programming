#include <stdio.h>

int main(void)
{
    int a[5];
    int *p;

    a[0] = 98;
    a[1] = 198;
    a[2] = 298;
    a[3] = 398;
    a[4] = 498;
    p = a + 2;
    /* Your line of code goes here (line 19) */
    ;
    printf("a[2] = %d\n", a[2]);
    return (0);
}
