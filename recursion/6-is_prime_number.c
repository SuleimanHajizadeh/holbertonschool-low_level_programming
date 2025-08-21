#include "main.h"

/**
 * check_prime - helper function to check divisibility
 * @n: number to check
 * @i: current divisor
 *
 * Return: 1 if prime, 0 otherwise
 */
int check_prime(int n, int i)
{
	if (i * i > n)  /* If divisor squared > n, no divisors left */
		return (1);
	if (n % i == 0) /* Found a divisor */
		return (0);
	return (check_prime(n, i + 1)); /* Check next divisor */
}

/**
 * is_prime_number - checks if a number is prime
 * @n: integer to check
 *
 * Return: 1 if prime, 0 otherwise
 */
int is_prime_number(int n)
{
	if (n <= 1)
		return (0);
	return (check_prime(n, 2));
}
