#include <stdio.h>

/**
 * main - finds and prints the largest prime factor of 612852475143
 *
 * Return: Always 0.
 */
int main(void)
{
	unsigned long n = 612852475143UL; /* 64-bit platformlarda kifayət edər */
	unsigned long i;

	while (n % 2 == 0)
		n /= 2;

	i = 3;
	while (i * i <= n)
	{
		while (n % i == 0)
			n /= i;
		i += 2;
	}

	printf("%lu\n", (n > 2) ? n : i - 2);

	return (0);
}
