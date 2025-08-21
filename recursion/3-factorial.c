#include "main.h"

/**
 * n is lower than 0
 * Factorial of 0 is 1

 return -1
 */
int factorial(int n)
{
    if (n < 0) 
        return (-1);

    if(n == 0 || n == 1)
    return(1);
        
    return (n * factorial(n-1));
}