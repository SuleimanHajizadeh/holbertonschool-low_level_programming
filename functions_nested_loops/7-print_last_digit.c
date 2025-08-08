#include "main.h"

/**
 * print_last_digit - prints and returns the last digit of a number
 * @n: the number to process
 *
 * Return: the value of the last digit
 */
int print_last_digit(int n)
{
	int lsd;

	lsd = n % 10;
	if (lsd < 0)
	{
		lsd = -lsd;
	}
	_putchar(lsd + '0');
	return (lsd);
}
