#include "main.h"

/**
 * print_number - prints an integer using _putchar
 * @n: integer to print
 */
void print_number(int n)
{
	if (n < 0)
	{
		_putchar('-');
		/* Convert to positive safely */
		if (n / 10 != 0)
			print_number(-(n / 10));
		_putchar('0' + -(n % 10));
	}
	else
	{
		if (n / 10 != 0)
			print_number(n / 10);
		_putchar('0' + (n % 10));
	}
}
