#include <stdio.h>
int main(void)
{
    int b[5];
    int *c;
    b[0] = 98;
    b[1] = 198;
    b[2] = 298;
    b[3] = 398;
    b[4] = 498;
    c = b + 2;
    /* Your line of code goes here (line 18) */
    ;
    printf("b[2] = %d\n", b[2]);
    return (0);
}
