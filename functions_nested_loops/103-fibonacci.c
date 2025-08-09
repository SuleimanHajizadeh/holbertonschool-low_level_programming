#include <stdio.h>

/**
 * main - prints the sum of even Fibonacci numbers
 *        not exceeding 4,000,000
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    unsigned long fib1 = 1, fib2 = 2, next;
    unsigned long sum = 2;  /* 2 is even, starts sum from 2 */

    while (1)
    {
        next = fib1 + fib2;
        if (next > 4000000)
            break;
        if (next % 2 == 0)
            sum += next;
        fib1 = fib2;
        fib2 = next;
    }

    printf("%lu\n", sum);

    return (0);
}
