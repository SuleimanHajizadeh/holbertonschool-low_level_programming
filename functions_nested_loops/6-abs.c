#include "main.h"

/**
 * _abs - returns the absolute value of an integer
 * @n: the integer to process
 *
 * Return: the absolute value of n
 */
int _abs(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}
